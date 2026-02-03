namespace ShoppingTunnel;

public class DiscountCalculator
{
    public virtual int Compute(int amount) {
        return amount > 100 ? 10 : 0;
    }
}