#include<iostream>
#include<string>
#include<vector>
using namespace std;

enum enRoomType { Single = 1, Double = 2, Suite = 3 };
enum enBookingStatus { Available = 1, Booked = 2 };

struct stRoom
{
    unsigned short RoomNumber = 0;
    enRoomType Type;
    double PricePerNight = 0;
    enBookingStatus Status = enBookingStatus::Available;
};

struct stBooking
{
    unsigned short BookingID = 0;
    stRoom Room;
    string GuestName = "";
    string CheckInDate = "";
    string CheckOutDate = "";
    unsigned short NumberOfNights = 0;
    double TotalPrice = 0;
};

int main()
{
    return 0;
}