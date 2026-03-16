#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

enum enRoomType { Single = 1, Double = 2, Suite = 3 };
enum enBookingStatus { Available = 1, Booked = 2 };

struct stRoom
{
    unsigned short RoomNumber = 0;
    enRoomType Type = enRoomType::Single;
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
string GetRoomTypeName(enRoomType Type)
{
    string arrRoomTypes[3] = { "Single", "Double", "Suite" };
    return arrRoomTypes[Type - 1];
}

string GetBookingStatusName(enBookingStatus Status)
{
    string arrStatus[2] = { "Available", "Booked" };
    return arrStatus[Status - 1];
}

stRoom CreateRoom(unsigned short RoomNumber, enRoomType Type,
    double PricePerNight)
{
    stRoom Room;
    Room.RoomNumber = RoomNumber;
    Room.Type = Type;
    Room.PricePerNight = PricePerNight;
    Room.Status = enBookingStatus::Available;
    return Room;
}

void LoadRoomList(vector<stRoom>& vRooms)
{
    vRooms.push_back(CreateRoom(101, enRoomType::Single, 50));
    vRooms.push_back(CreateRoom(102, enRoomType::Single, 50));
    vRooms.push_back(CreateRoom(201, enRoomType::Double, 100));
    vRooms.push_back(CreateRoom(202, enRoomType::Double, 100));
    vRooms.push_back(CreateRoom(301, enRoomType::Suite, 250));
    vRooms.push_back(CreateRoom(302, enRoomType::Suite, 250));
}

void PrintRoomList(vector<stRoom> vRooms)
{
    cout << "\n";
    cout << left
        << setw(10) << "Room No"
        << setw(12) << "Type"
        << setw(15) << "Price/Night"
        << setw(12) << "Status" << "\n";
    cout << string(49, '-') << "\n";

    for (stRoom& Room : vRooms)
    {
        cout << left
            << setw(10) << Room.RoomNumber
            << setw(12) << GetRoomTypeName(Room.Type)
            << setw(15) << Room.PricePerNight
            << setw(12) << GetBookingStatusName(Room.Status) << "\n";
    }
    cout << string(49, '-') << "\n";
}
int main()
{
    return 0;
}