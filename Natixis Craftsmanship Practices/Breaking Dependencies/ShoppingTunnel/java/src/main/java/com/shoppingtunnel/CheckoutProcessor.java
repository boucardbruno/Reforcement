package com.shoppingtunnel;

import com.shoppingtunnel.externallibrary.ExternalTax;
import com.shoppingtunnel.externallibrary.ExternalLibrarySideEffectError;

public class CheckoutProcessor {

    public int process(CartData data) throws ExternalLibrarySideEffectError {
        int discount = 0;

        DiscountCalculator calc;
        if (data.vip) {
            calc = new VipDiscountCalculator();
        } else {
            calc = new DiscountCalculator();
        }

        if (data.total > 0) {
            discount = calc.compute(data.total);
        }

        ExternalTax tax = new ExternalTax();
        int taxed = data.total - discount;

        if (taxed > 0) {
            taxed += taxed * tax.rate(data.country) / 100;
        }

        return taxed;
    }
}
