#include "CheckoutProcessor.h"

#include <memory>

#include "DiscountCalculator.h"
#include "ExternalTax.h"
#include "VipDiscountCalculator.h"

int CheckoutProcessor::process(const CartData &data) {
    int discount = 0;

    std::unique_ptr<DiscountCalculator> calc;

    if (data.vip) {
        calc = std::make_unique<VipDiscountCalculator>();
    } else {
        calc = std::make_unique<DiscountCalculator>();
    }

    if (data.total > 0) {
        discount = calc->compute(data.total);
    }

    ExternalTax tax;
    int taxed = data.total - discount;

    if (taxed > 0) {
        taxed += taxed * tax.rate(data.country) / 100;
    }

    return taxed;
}
