namespace MarketTrading.External;

[DotNotModify]
public class NativeMarketSql
{
    public string LoadPositionAsXml(string trader, string symbol) {
        throw new ExternalSideEffectException("SQL XML load forbidden in test");
    }

    public void PersistTradeAsXml(string tradeXml) {
        throw new ExternalSideEffectException("SQL XML persist forbidden in test");
    }
}