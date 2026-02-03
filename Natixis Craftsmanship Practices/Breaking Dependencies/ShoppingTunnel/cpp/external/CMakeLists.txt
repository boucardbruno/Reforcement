add_library(externalTax SHARED
        src/ExternalTax.cpp
)

target_include_directories(externalTax
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
