add_library(HotelReservationLib
    STATIC
    BookingDecision.cpp
)

target_link_libraries(HotelReservationLib
    ExternalLib
)

target_include_directories(HotelReservationLib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)