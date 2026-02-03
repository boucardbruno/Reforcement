#include "NativeMarketSql.h"
#include "ExternalSideEffectException.h"

std::string NativeMarketSql::loadPositionAsXml(const std::string &, const std::string &) {
    throw ExternalSideEffectException("SQL XML load forbidden in test");
}

void NativeMarketSql::persistTradeAsXml(const std::string &) {
    throw ExternalSideEffectException("SQL XML persist forbidden in test");
}
