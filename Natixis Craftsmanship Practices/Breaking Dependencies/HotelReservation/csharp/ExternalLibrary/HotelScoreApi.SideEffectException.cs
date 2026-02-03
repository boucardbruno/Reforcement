namespace HotelReservation.ExternalLibrary;

public partial class HotelScoreApi
{
    [DoNotModify]
    public class SideEffectException : Exception
    {
        public SideEffectException(string hotelScoreApiUnavailable)
        {
            throw new NotImplementedException();
        }
    }
}