package com.markettrading;

import com.markettrading.external.*;

public class UltimateTradingEngine {

    public String processOrder(String xmlOrder) throws ExternalSideEffectException {

        XmlObjectMapper mapper = new XmlObjectMapper();
        NativeMarketSql sql = new NativeMarketSql();
        MarketHttpClient http = new MarketHttpClient();
        MarketChaos chaos = new MarketChaos();

        OrderXml order = mapper.read(xmlOrder, OrderXml.class);

        ExecutionXml exec = new ExecutionXml();
        exec.executed = false;
        exec.status = "INIT";
        exec.avgPrice = 0.0;

        if (!MarketContext.marketOpen) {
            exec.status = "MARKET_CLOSED";
            return mapper.write(exec);
        }

        MarketContext.executionsToday++;

        int riskScore = 0;

        if (order.qty > 1000) {
            riskScore += 2;
        }

        if ("SELL".equals(order.side)) {
            riskScore++;
        }

        if ((order.flags & 1) == 1) {
            riskScore--;
        }

        int marketStatus = http.getStatus(
                "http://exchange/api/status?symbol=" + order.symbol
        );

        if (marketStatus != 200) {
            exec.status = "MARKET_DOWN";
            return mapper.write(exec);
        }

        String positionXml = sql.loadPositionAsXml(order.trader, order.symbol);

        // BUG: position never really parsed
        if (positionXml != null && positionXml.contains("<qty>")) {
            if ("SELL".equals(order.side) && order.qty > 500) {
                riskScore += 3;
            }
        }

        long now = chaos.now();
        if (now % 2 == 0) {
            riskScore += chaos.rnd(3);
        }

        double price = order.price;

        if (MarketContext.lastPrices.containsKey(order.symbol)) {
            double last = MarketContext.lastPrices.get(order.symbol);
            if (Math.abs(last - price) > 2) {
                price = (last + price) / 2;
            }
        }

        if (riskScore > 3) {
            exec.status = "REJECTED_RISK";
        } else {
            double execPrice;
            if (chaos.rnd(10) > 7) {
                execPrice = price + 0.1;
            } else {
                execPrice = price - 0.1;
            }

            exec.executed = true;
            exec.executionId = order.id + "-" + MarketContext.executionsToday;
            exec.avgPrice = execPrice;
            exec.status = "EXECUTED";

            MarketContext.lastPrices.put(order.symbol, execPrice);

            String tradeXml =
                    "<trade>" +
                            "<id>" + exec.executionId + "</id>" +
                            "<symbol>" + order.symbol + "</symbol>" +
                            "<qty>" + order.qty + "</qty>" +
                            "<price>" + execPrice + "</price>" +
                            "</trade>";

            sql.persistTradeAsXml(tradeXml);
        }

        return mapper.write(exec);
    }
}
