namespace ShoppingTunnel;

public class VipDiscountCalculator : DiscountCalculator
{
    public override int Compute(int amount) {
        if (amount < 50) {
            throw new System.InvalidOperationException("VIP cannot have small cart");
        }
        return 20;
    }
}