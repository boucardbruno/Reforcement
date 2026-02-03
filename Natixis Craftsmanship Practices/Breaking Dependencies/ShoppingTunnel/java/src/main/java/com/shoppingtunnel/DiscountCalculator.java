package com.shoppingtunnel;

public class DiscountCalculator {

    public int compute(int amount) {
        return amount > 100 ? 10 : 0;
    }
}

