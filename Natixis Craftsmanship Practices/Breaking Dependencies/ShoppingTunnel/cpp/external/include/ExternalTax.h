#ifndef SHOPPINGTUNEL_EXTERNALTAX_H
#define SHOPPINGTUNEL_EXTERNALTAX_H
#include <string>

#include <stdexcept>

class ExternalLibrarySideEffectError : public std::runtime_error {
public:
    explicit ExternalLibrarySideEffectError(const std::string& message)
        : std::runtime_error(message) {}
};

class ExternalTax {
public:
    int rate(const std::string& /*country*/);
};

#endif //SHOPPINGTUNEL_EXTERNALTAX_H