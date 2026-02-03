namespace MarketTrading;

public class OrderXml
{
    public string Id = string.Empty;
    public string Symbol = string.Empty;
    public int Qty;
    public double Price;
    public string Side = string.Empty;     // BUY / SELL
    public string Trader = string.Empty;
    public int Flags;  
}