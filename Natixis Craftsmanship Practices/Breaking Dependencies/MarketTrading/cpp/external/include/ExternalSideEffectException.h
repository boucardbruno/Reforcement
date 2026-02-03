#ifndef MARKETDATA_EXTERNALSIDEEFFECTEXCEPTION_H
#define MARKETDATA_EXTERNALSIDEEFFECTEXCEPTION_H
#include <stdexcept>

class ExternalSideEffectException : public std::runtime_error {
public:
    explicit ExternalSideEffectException(const std::string& msg)
        : std::runtime_error(msg) {}
};

#endif //MARKETDATA_EXTERNALSIDEEFFECTEXCEPTION_H