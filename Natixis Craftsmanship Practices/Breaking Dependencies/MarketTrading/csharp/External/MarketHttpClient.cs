namespace MarketTrading.External;

[DotNotModify]
public class MarketHttpClient
{
    public int GetStatus(String url)
    {
        throw new ExternalSideEffectException("HTTP call forbidden in test");
    }
}