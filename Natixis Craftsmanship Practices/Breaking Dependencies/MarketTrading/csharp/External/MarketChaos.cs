namespace MarketTrading.External;

[DotNotModify]
public class MarketChaos
{
    public long Now() {
        return DateTime.Now.Millisecond;
    }

    public int Rnd(int bound) {
        return new Random().Next(bound);
    }    
}