#ifndef MARKETDATA_MARKETHTTPCLIENT_H
#define MARKETDATA_MARKETHTTPCLIENT_H

#include <string>

class MarketHttpClient {
public:
    int getStatus(const std::string& /*url*/);
};

#endif //MARKETDATA_MARKETHTTPCLIENT_H
