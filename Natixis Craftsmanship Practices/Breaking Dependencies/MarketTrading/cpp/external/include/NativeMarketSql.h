#ifndef MARKETDATA_NATIVEMARKETSQL_H
#define MARKETDATA_NATIVEMARKETSQL_H
#include <string>

class NativeMarketSql {
public:
    std::string loadPositionAsXml(
        const std::string& /*trader*/,
        const std::string& /*symbol*/
    );

    void persistTradeAsXml(const std::string& /*tradeXml*/);
};

#endif //MARKETDATA_NATIVEMARKETSQL_H
