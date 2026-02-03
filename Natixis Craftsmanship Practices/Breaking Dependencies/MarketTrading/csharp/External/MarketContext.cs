namespace MarketTrading.External;

[DotNotModify]
public static class MarketContext
{
    public static readonly bool MarketOpen = true;
    public static int ExecutionsToday = 0;
    public static readonly Dictionary<string, double> LastPrices = new Dictionary<string, double>();
}