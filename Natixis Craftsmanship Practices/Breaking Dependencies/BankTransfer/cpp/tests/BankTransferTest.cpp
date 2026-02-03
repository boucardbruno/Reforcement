#include "MegaTransferEngine.h"
#include "gtest/gtest.h"

TEST(BankTransfer, should_fail) {
    MegaTransferEngine engine;
    TData data;
    engine.doIt(data, "");
}