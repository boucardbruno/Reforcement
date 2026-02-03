add_library(BankTransferLib
        STATIC
        MegaTransferEngine.cpp
)

target_include_directories(BankTransferLib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(BankTransferLib
        ExternalLib
)