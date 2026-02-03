#include "HotelScoreApi.h"

#include "SideEffectException.h"

int HotelScoreApi::score(const std::string &) {
    throw SideEffectException("Hotel score API unavailable");
}
