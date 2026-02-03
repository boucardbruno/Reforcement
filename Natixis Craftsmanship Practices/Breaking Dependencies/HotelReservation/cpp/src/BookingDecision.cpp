#include "BookingDecision.h"

#include <memory>

#include "ClockService.h"
#include "HotelScoreApi.h"

bool BookingDecision::accept(const BookingInput &in) {

    int score = 0;

    for (int i = 0; i < in.nights; ++i) {
        if (in.guests > 2) {
            if (i % 2 == 0) {
                score += 2;
            } else {
                score += 1;
            }
        } else {
            score++;
        }
    }

    auto clock = std::make_unique<ClockService>();
    if (clock->hour() < 7) {
        score--;
    }

    auto api = std::make_unique<HotelScoreApi>();
    score += api->score(in.hotel);

    if (score > 5) {
        if (in.nights > 10) {
            return score > 8;
        }
        return true;
    }

    return false;
}
