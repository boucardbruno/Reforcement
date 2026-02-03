package com.markettrading.external;

@DoNotModify
public class MarketHttpClient {

    public int getStatus(String url) throws ExternalSideEffectException {
        throw new ExternalSideEffectException("HTTP call forbidden in test");
    }
}
