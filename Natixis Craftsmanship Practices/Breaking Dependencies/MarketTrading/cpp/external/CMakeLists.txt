add_library(ExternalLib SHARED
        src/MarketChaos.cpp
        src/MarketHttpClient.cpp
        src/NativeMarketSql.cpp
)

target_include_directories(ExternalLib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)