using HotelReservation.ExternalLibrary;

namespace HotelReservation;

public class BookingDecision
{
    public bool Accept(BookingInput input)
    {
        var score = 0;

        for (var i = 0; i < input.Nights; i++)
        {
            if (input.Guests > 2)
            {
                if (i % 2 == 0)
                {
                    score += 2;
                }
                else
                {
                    score += 1;
                }
            }
            else
            {
                score++;
            }
        }

        var clock = new ClockService();
        if (clock.Hour() < 7)
        {
            score--;
        }

        var api = new HotelScoreApi();
        score += api.Score(input.Hotel);

        if (score > 5)
        {
            if (input.Nights > 10)
            {
                return score > 8;
            }

            return true;
        }

        return false;
    }
}