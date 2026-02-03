namespace HotelReservation.ExternalLibrary;

public partial class HotelScoreApi
{
    [DoNotModify]
    public int Score(string hotel)
    {
        throw new SideEffectException("Hotel score API unavailable");
    }
}

