namespace ShoppingTunnel.ExternalLibrary;

[DoNotModify]
public class ExternalTax
{
    public int Rate(String country)
    {
        throw new ExternalLibrarySideEffectError("Tax system unavailable in test");
    }
}