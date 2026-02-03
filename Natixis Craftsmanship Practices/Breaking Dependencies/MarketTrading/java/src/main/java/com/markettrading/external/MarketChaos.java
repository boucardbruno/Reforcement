package com.markettrading.external;

import java.util.Random;

@DoNotModify
public class MarketChaos {

    public long now() {
        return System.currentTimeMillis();
    }

    public int rnd(int bound) {
        return new Random().nextInt(bound);
    }
}
