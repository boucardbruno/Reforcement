#ifndef BANKTRANSFER_MEGATRANSFERENGINE_H
#define BANKTRANSFER_MEGATRANSFERENGINE_H
#include <string>
#include <unordered_map>

class GlobalState {
public:
    static inline int transferCount = 0;
    static inline bool maintenance = false;
    static inline std::unordered_map<std::string, int> cache{};
};

struct TData {
    std::string a; // from
    std::string b; // to
    int c;         // amount
    bool d;        // vip
};

class MegaTransferEngine {
public:
    bool doIt(const TData& d, const std::string& channel);
};

#endif //BANKTRANSFER_MEGATRANSFERENGINE_H