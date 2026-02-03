package com.hotelreservation;

import com.hotelreservation.externallibrary.DoNotModify;

import java.time.LocalDateTime;

@DoNotModify
public class ClockService {

    public int hour() {
        return LocalDateTime.now().getHour();
    }
}
