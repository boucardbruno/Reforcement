#include "VipDiscountCalculator.h"
#include <stdexcept>

int VipDiscountCalculator::compute(int amount) {
    if (amount < 50) {
        throw std::logic_error("VIP cannot have small cart");
    }
    return 20;
}
