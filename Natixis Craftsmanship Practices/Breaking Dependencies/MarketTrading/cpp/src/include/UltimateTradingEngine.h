#ifndef MARKETDATA_ULTIMATETRADINGENGINE_H
#define MARKETDATA_ULTIMATETRADINGENGINE_H
#include <string>
#include <unordered_map>

struct ExecutionXml {
    bool executed = false;
    std::string executionId;
    std::string status;
    double avgPrice = 0.0;
};

struct MarketContext {
    static inline bool marketOpen = true;
    static inline int executionsToday = 0;
    static inline std::unordered_map<std::string, double> lastPrices{};
};

struct OrderXml {
    std::string id;
    std::string symbol;
    int qty = 0;
    double price = 0.0;
    std::string side;   // BUY / SELL
    std::string trader;
    int flags = 0;
};

class UltimateTradingEngine {
public:
    UltimateTradingEngine() = default;

    std::string processOrder(const std::string& xmlOrder);
};



#endif //MARKETDATA_ULTIMATETRADINGENGINE_H
