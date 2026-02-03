#include "DiscountCalculator.h"

int DiscountCalculator::compute(int amount) {
    return amount > 100 ? 10 : 0;
}
