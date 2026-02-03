#ifndef BANKTRANSFER_EXTERNALSIDEEFFECTEXCEPTION_H
#define BANKTRANSFER_EXTERNALSIDEEFFECTEXCEPTION_H
#include <stdexcept>

class ExternalSideEffectException : public std::runtime_error {
public:
    explicit ExternalSideEffectException(const std::string& msg)
        : std::runtime_error(msg) {}
};


#endif //BANKTRANSFER_EXTERNALSIDEEFFECTEXCEPTION_H