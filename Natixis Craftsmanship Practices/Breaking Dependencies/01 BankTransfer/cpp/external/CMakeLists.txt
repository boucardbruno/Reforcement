add_library(ExternalLib
        SHARED
        src/HttpRiskClient.cpp
        src/NativeSql.cpp
)

target_include_directories(ExternalLib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)