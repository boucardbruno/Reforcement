package com.markettrading.external;

import java.util.HashMap;
import java.util.Map;

@DoNotModify
public class MarketContext {

    public static boolean marketOpen = true;
    public static int executionsToday = 0;
    public static Map<String, Double> lastPrices = new HashMap<>();
}
