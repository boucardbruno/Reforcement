namespace MarketTrading.External;

[DotNotModify]
public class ExternalSideEffectException : Exception
{
    public ExternalSideEffectException(string message, Exception? inner = null)
        : base(message, inner)
    {
    }
}