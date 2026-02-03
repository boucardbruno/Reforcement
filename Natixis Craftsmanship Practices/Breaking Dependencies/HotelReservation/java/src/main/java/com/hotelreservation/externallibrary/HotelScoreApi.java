package com.hotelreservation.externallibrary;

@DoNotModify
public class HotelScoreApi {

    public int score(String hotel) throws SideEffectException {
        throw new SideEffectException("Hotel score API unavailable");
    }
}
