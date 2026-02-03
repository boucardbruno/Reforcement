#ifndef HOTELRESERVATION_BOOKINGDECISION_H
#define HOTELRESERVATION_BOOKINGDECISION_H
#include <string>


struct BookingInput {
    std::string hotel;
    int nights = 0;
    int guests = 0;
};

class BookingDecision {
public:
    bool accept(const BookingInput& in);
};


#endif //HOTELRESERVATION_BOOKINGDECISION_H