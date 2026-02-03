package com.markettrading.external;

@DoNotModify
public class NativeMarketSql {

    public String loadPositionAsXml(String trader, String symbol) throws ExternalSideEffectException {
        throw new ExternalSideEffectException("SQL XML load forbidden in test");
    }

    public void persistTradeAsXml(String tradeXml) throws ExternalSideEffectException {
        throw new ExternalSideEffectException("SQL XML persist forbidden in test");
    }
}
