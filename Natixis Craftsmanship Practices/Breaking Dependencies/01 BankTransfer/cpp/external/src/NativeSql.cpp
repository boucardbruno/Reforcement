#include "NativeSql.h"
#include "ExternalSideEffectException.h"

int NativeSql::queryBalance(const std::string &acc) {
    throw ExternalSideEffectException(
        "SQL access forbidden in test"
    );
}

void NativeSql::updateBalance(const std::string &acc, int value) {
    throw ExternalSideEffectException(
        "SQL update forbidden in test"
    );
}
