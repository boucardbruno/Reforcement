using ShoppingTunnel.ExternalLibrary;

namespace ShoppingTunnel;

public class CheckoutProcessor
{
    public int Process(CartData data)
    {
        var discount = 0;

        DiscountCalculator calc;
        
        if (data.Vip)
        {
            calc = new VipDiscountCalculator();
        }
        else
        {
            calc = new DiscountCalculator();
        }

        if (data.Total > 0)
        {
            discount = calc.Compute(data.Total);
        }

        var tax = new ExternalTax();
        
        var taxed = data.Total - discount;

        if (taxed > 0)
        {
            taxed += taxed * tax.Rate(data.Country) / 100;
        }

        return taxed;
    }
}