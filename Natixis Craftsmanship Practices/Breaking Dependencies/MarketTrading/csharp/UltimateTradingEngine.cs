using MarketTrading.External;

namespace MarketTrading;

public class UltimateTradingEngine
{
  public String ProcessOrder(string xmlOrder) {

        var mapper = new XmlObjectMapper();
        var sql = new NativeMarketSql();
        var http = new MarketHttpClient();
        var chaos = new MarketChaos();

        var order = mapper.Read<OrderXml>(xmlOrder, typeof(OrderXml));

        var exec = new ExecutionXml();
        exec.Executed = false;
        exec.Status = "INIT";
        exec.AvgPrice = 0.0;

        if (!MarketContext.MarketOpen) {
            exec.Status = "MARKET_CLOSED";
            return mapper.Write(exec);
        }

        MarketContext.ExecutionsToday++;

        var riskScore = 0;

        if (order.Qty > 1000) {
            riskScore += 2;
        }

        if ("SELL".Equals(order.Side)) {
            riskScore++;
        }

        if ((order.Flags & 1) == 1) {
            riskScore--;
        }

        var marketStatus = http.GetStatus(
                "http://exchange/api/status?symbol=" + order.Symbol
        );

        if (marketStatus != 200) {
            exec.Status = "MARKET_DOWN";
            return mapper.Write(exec);
        }

        var positionXml = sql.LoadPositionAsXml(order.Trader, order.Symbol);

        // BUG: position never really parsed
        if (positionXml.Contains("<qty>")) {
            if ("SELL".Equals(order.Side) && order.Qty > 500) {
                riskScore += 3;
            }
        }

        var now = chaos.Now();
        if (now % 2 == 0) {
            riskScore += chaos.Rnd(3);
        }

        var price = order.Price;

        if (MarketContext.LastPrices.ContainsKey(order.Symbol)) {
            var last = MarketContext.LastPrices[order.Symbol];
            if (Math.Abs(last - price) > 2) {
                price = (last + price) / 2;
            }
        }

        if (riskScore > 3) {
            exec.Status = "REJECTED_RISK";
        } else {
            double execPrice;
            if (chaos.Rnd(10) > 7) {
                execPrice = price + 0.1;
            } else {
                execPrice = price - 0.1;
            }

            exec.Executed = true;
            exec.ExecutionId = order.Id + "-" + MarketContext.ExecutionsToday;
            exec.AvgPrice = execPrice;
            exec.Status = "EXECUTED";

            MarketContext.LastPrices[order.Symbol] = execPrice;

            var tradeXml =
                    "<trade>" +
                            "<id>" + exec.ExecutionId + "</id>" +
                            "<symbol>" + order.Symbol + "</symbol>" +
                            "<qty>" + order.Qty + "</qty>" +
                            "<price>" + execPrice + "</price>" +
                            "</trade>";

            sql.PersistTradeAsXml(tradeXml);
        }

        return mapper.Write(exec);
    }
}