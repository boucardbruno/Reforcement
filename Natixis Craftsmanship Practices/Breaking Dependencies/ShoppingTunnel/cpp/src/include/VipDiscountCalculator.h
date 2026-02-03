#ifndef SHOPPINGTUNEL_VIPDISCOUNTCALCULATOR_H
#define SHOPPINGTUNEL_VIPDISCOUNTCALCULATOR_H

#include "DiscountCalculator.h"

// VipDiscountCalculator
class VipDiscountCalculator : public DiscountCalculator {
public:
    int compute(int amount) override;
};

#endif //SHOPPINGTUNEL_VIPDISCOUNTCALCULATOR_H