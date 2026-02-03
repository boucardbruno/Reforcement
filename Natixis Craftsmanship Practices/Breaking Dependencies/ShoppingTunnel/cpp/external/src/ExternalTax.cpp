
#include "ExternalTax.h"

int ExternalTax::rate(const std::string &) {
    throw ExternalLibrarySideEffectError("Tax system unavailable in test");
}
