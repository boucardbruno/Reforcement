#include "MarketChaos.h"

#include <cstdlib>
#include <ctime>

long MarketChaos::now() const {
    return std::time(nullptr) * 1000;
}

int MarketChaos::rnd(int bound) const {
    return std::rand() % bound;
}