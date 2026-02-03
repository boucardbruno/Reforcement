#include "UltimateTradingEngine.h"
#include "gtest/gtest.h"

TEST(MarketTrading, should_fail) {
    UltimateTradingEngine engine;
    engine.processOrder("");
}
