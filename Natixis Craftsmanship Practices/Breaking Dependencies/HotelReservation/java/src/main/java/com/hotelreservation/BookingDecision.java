package com.hotelreservation;

import com.hotelreservation.externallibrary.HotelScoreApi;
import com.hotelreservation.externallibrary.SideEffectException;

public class BookingDecision {

    public boolean accept(BookingInput in) throws SideEffectException {

        int score = 0;

        for (int i = 0; i < in.nights; i++) {
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

        ClockService clock = new ClockService();
        if (clock.hour() < 7) {
            score--;
        }

        HotelScoreApi api = new HotelScoreApi();
        score += api.score(in.hotel);

        if (score > 5) {
            if (in.nights > 10) {
                return score > 8;
            }
            return true;
        }

        return false;
    }
}
