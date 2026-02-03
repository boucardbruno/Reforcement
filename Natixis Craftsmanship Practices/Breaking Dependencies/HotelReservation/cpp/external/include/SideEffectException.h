#ifndef HOTELRESERVATION_SIDEEFFECTEXCEPTION_H
#define HOTELRESERVATION_SIDEEFFECTEXCEPTION_H
#include <stdexcept>

class SideEffectException : public std::runtime_error {
public:
    explicit SideEffectException(const std::string& msg)
        : std::runtime_error(msg) {}
};

#endif //HOTELRESERVATION_SIDEEFFECTEXCEPTION_H