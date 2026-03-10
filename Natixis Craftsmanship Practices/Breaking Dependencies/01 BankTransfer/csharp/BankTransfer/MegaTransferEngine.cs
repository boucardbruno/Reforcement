using BankTransfer.External;

namespace BankTransfer;

public class MegaTransferEngine
{
    public bool DoIt(TData d, string channel)
    {
        if (GlobalState.Maintenance) throw new IllegalStateException("Maintenance");

        GlobalState.TransferCount++;

        var fee = 0;

        if ("MOBILE".Equals(channel))
        {
            fee += 2;
        }
        else
        {
            if ("WEB".Equals(channel)) fee += 1;
        }

        if (d.D) fee--;

        var net = d.C - fee;

        // BUG volontaire : net peut être négatif mais on continue
        var sql = new NativeSql();

        int balance;
        if (GlobalState.Cache.ContainsKey(d.A))
        {
            balance = GlobalState.Cache[d.A];
        }
        else
        {
            balance = sql.QueryBalance(d.A);
            GlobalState.Cache[d.A] = balance;
        }

        var http = new HttpRiskClient();

        if (http.Risky(d.A, net))
            if (!d.D)
                return false;

        sql.UpdateBalance(d.A, balance - d.C);

        if (net % 2 == 0)
        {
            sql.UpdateBalance(d.B, net);
        }
        else
        {
            sql.UpdateBalance(d.B, net - 1);
            sql.UpdateBalance(d.B, 1);
        }

        if (GlobalState.TransferCount > 100) GlobalState.Cache.Clear();

        return true;
    }
}