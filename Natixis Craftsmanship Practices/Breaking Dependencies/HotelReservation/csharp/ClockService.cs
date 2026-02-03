using HotelReservation.ExternalLibrary;

namespace HotelReservation;

[DoNotModify]
public class ClockService {

    public int Hour() {
        return DateTime.Now.Hour;
    }
}