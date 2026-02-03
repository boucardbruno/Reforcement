add_library(ExternalLib
    SHARED
        src/HotelScoreApi.cpp
        src/ClockService.cpp
)

target_include_directories(ExternalLib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)