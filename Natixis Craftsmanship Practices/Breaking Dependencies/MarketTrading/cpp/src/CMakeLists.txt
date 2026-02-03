add_library(marketTradingLib
        UltimateTradingEngine.cpp
)

target_link_libraries(marketTradingLib
        PUBLIC
        ExternalLib
)

target_include_directories(marketTradingLib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)