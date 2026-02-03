#ifndef BANKTRANSFER_NATIVESQL_H
#define BANKTRANSFER_NATIVESQL_H
#include <string>

class NativeSql {
public:
    int queryBalance(const std::string& acc);
    void updateBalance(const std::string& acc, int value);
};

#endif //BANKTRANSFER_NATIVESQL_H