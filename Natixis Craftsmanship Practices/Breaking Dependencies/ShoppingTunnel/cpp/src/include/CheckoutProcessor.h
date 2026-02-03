#ifndef SHOPPINGTUNEL_CHECKOUTPROCESSOR_H
#define SHOPPINGTUNEL_CHECKOUTPROCESSOR_H

#include <string>

struct CartData {
    int total;
    std::string country;
    bool vip;
};

class CheckoutProcessor {
public:
    int process(const CartData& data);
};

#endif //SHOPPINGTUNEL_CHECKOUTPROCESSOR_H