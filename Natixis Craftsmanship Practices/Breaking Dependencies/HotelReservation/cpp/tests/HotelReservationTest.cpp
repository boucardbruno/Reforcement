#include "BookingDecision.h"
#include "gtest/gtest.h"

TEST(HotelReservation, should_fail) {
    BookingDecision booking_decision;
    BookingInput booking_input;
    booking_decision.accept(booking_input);
}
