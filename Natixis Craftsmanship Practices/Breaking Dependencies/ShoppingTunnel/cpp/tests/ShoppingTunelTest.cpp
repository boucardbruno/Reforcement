//
// Created by sebastien-manicon on 21/01/2026.
//

#include <gtest/gtest.h>

#include "CheckoutProcessor.h"

TEST(Test, should_fail) {
    CheckoutProcessor processor;
    CartData carte;
    processor.process(carte);
}