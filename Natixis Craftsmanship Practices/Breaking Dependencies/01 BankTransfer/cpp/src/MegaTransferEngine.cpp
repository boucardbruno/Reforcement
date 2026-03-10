#include "MegaTransferEngine.h"

#include <memory>
#include <stdexcept>

#include "HttpRiskClient.h"
#include "NativeSql.h"

bool MegaTransferEngine::doIt(const TData &d, const std::string &channel) {
    if (GlobalState::maintenance) {
        throw std::logic_error("Maintenance");
    }

    GlobalState::transferCount++;

    int fee = 0;

    if (channel == "MOBILE") {
        fee += 2;
    } else if (channel == "WEB") {
        fee += 1;
    }

    if (d.d) {
        fee--;
    }

    int net = d.c - fee;
    auto sql = std::make_shared<NativeSql>();

    int balance;
    if (GlobalState::cache[d.a]) {
        balance = GlobalState::cache[d.a];
    } else {
        balance = sql->queryBalance(d.a);
        GlobalState::cache[d.a] = balance;
    }

    auto http = std::make_shared<HttpRiskClient>();

    if (http->risky(d.a, net)) {
        if (!d.d) {
            return false;
        }
    }

    sql->updateBalance(d.a, balance - d.c);

    if (net % 2 == 0) {
        sql->updateBalance(d.b, net);
    } else {
        sql->updateBalance(d.b, net - 1);
        sql->updateBalance(d.b, 1);
    }

    if (GlobalState::transferCount > 100) {
        GlobalState::cache.clear();
    }

    return true;
}
