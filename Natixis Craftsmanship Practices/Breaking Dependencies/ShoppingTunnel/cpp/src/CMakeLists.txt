add_library(shoppingTunelLib STATIC
        CheckoutProcessor.cpp
        DiscountCalculator.cpp
        VipDiscountCalculator.cpp
)

target_link_libraries(shoppingTunelLib
        PRIVATE externalTax
)

target_include_directories(shoppingTunelLib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
