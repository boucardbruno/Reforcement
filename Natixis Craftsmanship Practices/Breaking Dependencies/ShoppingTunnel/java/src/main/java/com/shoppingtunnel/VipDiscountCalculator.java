package com.shoppingtunnel;

public class VipDiscountCalculator extends DiscountCalculator {

    @Override
    public int compute(int amount) {
        if (amount < 50) {
            throw new IllegalStateException("VIP cannot have small cart");
        }
        return 20;
    }


}

