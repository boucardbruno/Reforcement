#ifndef MARKETDATA_MARKETCHAOS_H
#define MARKETDATA_MARKETCHAOS_H

class MarketChaos {
public:
    [[nodiscard]] long now() const;

    [[nodiscard]] int rnd(int bound) const;
};

#endif //MARKETDATA_MARKETCHAOS_H
