#ifndef SHOPPINGTUNEL_DISCOUNTCALCULATOR_H
#define SHOPPINGTUNEL_DISCOUNTCALCULATOR_H

class DiscountCalculator {
public:
    virtual ~DiscountCalculator() = default;

    virtual int compute(int amount);
};

#endif //SHOPPINGTUNEL_DISCOUNTCALCULATOR_H