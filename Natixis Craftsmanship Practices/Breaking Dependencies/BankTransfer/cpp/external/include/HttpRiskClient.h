#ifndef BANKTRANSFER_HTTPRISKCLIENT_H
#define BANKTRANSFER_HTTPRISKCLIENT_H
#include <string>

class HttpRiskClient {
public:
    bool risky(const std::string& acc, int amount);
};

#endif //BANKTRANSFER_HTTPRISKCLIENT_H