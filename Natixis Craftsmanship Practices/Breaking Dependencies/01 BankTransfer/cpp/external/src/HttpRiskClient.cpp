#include "HttpRiskClient.h"
#include "ExternalSideEffectException.h"

#include <string>

bool HttpRiskClient::risky(const std::string &acc, int amount) {
    throw ExternalSideEffectException(
        "HTTP risk service forbidden in test"
    );
}
