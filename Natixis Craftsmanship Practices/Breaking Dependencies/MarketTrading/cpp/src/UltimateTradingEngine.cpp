
#include "UltimateTradingEngine.h"

#include <string>

#include "MarketChaos.h"
#include "MarketHttpClient.h"
#include "NativeMarketSql.h"
#include "XmlParser.h"

std::string UltimateTradingEngine::processOrder(const std::string &xmlOrder) {

    NativeMarketSql sql;
    MarketHttpClient http;
    MarketChaos chaos;

    XmlParser<OrderXml> mapperOrder;
    OrderXml order = mapperOrder.read(xmlOrder);

    ExecutionXml exec;
    exec.executed = false;
    exec.status = "INIT";
    exec.avgPrice = 0.0;

    if (!MarketContext::marketOpen) {
        exec.status = "MARKET_CLOSED";
        XmlParser<ExecutionXml> mapperExecution;
        return mapperExecution.write(exec);
    }

    MarketContext::executionsToday++;

    int riskScore = 0;

    if (order.qty > 1000) riskScore += 2;
    if (order.side == "SELL") riskScore++;
    if ((order.flags & 1) == 1) riskScore--;

    int marketStatus = http.getStatus(
        "http://exchange/api/status?symbol=" + order.symbol
    );

    if (marketStatus != 200) {
        exec.status = "MARKET_DOWN";
        XmlParser<ExecutionXml> mapperExecution;
        return mapperExecution.write(exec);

    }

    std::string positionXml =
            sql.loadPositionAsXml(order.trader, order.symbol);

    if (!positionXml.empty() &&
        positionXml.find("<qty>") != std::string::npos) {
        if (order.side == "SELL" && order.qty > 500) {
            riskScore += 3;
        }
    }

    long now = chaos.now();
    if (now % 2 == 0) {
        riskScore += chaos.rnd(3);
    }

    double price = order.price;

    auto it = MarketContext::lastPrices.find(order.symbol);
    if (it != MarketContext::lastPrices.end()) {
        double last = it->second;
        if (std::abs(last - price) > 2.0) {
            price = (last + price) / 2.0;
        }
    }

    if (riskScore > 3) {
        exec.status = "REJECTED_RISK";
    } else {
        double execPrice =
                (chaos.rnd(10) > 7) ? price + 0.1 : price - 0.1;

        exec.executed = true;
        exec.executionId =
                order.id + "-" + std::to_string(MarketContext::executionsToday);
        exec.avgPrice = execPrice;
        exec.status = "EXECUTED";

        MarketContext::lastPrices[order.symbol] = execPrice;

        std::string tradeXml =
                "<trade>"
                "<id>" + exec.executionId + "</id>"
                "<symbol>" + order.symbol + "</symbol>"
                "<qty>" + std::to_string(order.qty) + "</qty>"
                "<price>" + std::to_string(execPrice) + "</price>"
                "</trade>";

        sql.persistTradeAsXml(tradeXml);
    }

    XmlParser<ExecutionXml> mapperExecution;
    return mapperExecution.write(exec);
}