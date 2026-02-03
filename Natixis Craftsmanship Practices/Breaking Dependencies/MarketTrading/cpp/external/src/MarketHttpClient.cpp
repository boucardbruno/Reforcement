#include "MarketHttpClient.h"
#include "ExternalSideEffectException.h"

int MarketHttpClient::getStatus(const std::string &) {
    throw ExternalSideEffectException("HTTP call forbidden in test");
}

