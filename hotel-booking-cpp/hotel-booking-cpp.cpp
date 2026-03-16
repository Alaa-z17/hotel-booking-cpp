#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<ctime>
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

void PrintRoomList(vector<stRoom> &vRooms)
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
int FindRoomIndexByNumber(unsigned short RoomNumber,
    vector<stRoom>& vRooms)
{
    for (int i = 0; i < vRooms.size(); i++)
    {
        if (vRooms[i].RoomNumber == RoomNumber)
            return i;
    }
    return -1;
}

bool IsRoomExist(unsigned short RoomNumber, vector<stRoom>& vRooms)
{
    return FindRoomIndexByNumber(RoomNumber, vRooms) != -1;
}

bool IsRoomAvailable(unsigned short RoomNumber, vector<stRoom>& vRooms)
{
    int Index = FindRoomIndexByNumber(RoomNumber, vRooms);
    if (Index == -1)
        return false;
    return vRooms[Index].Status == enBookingStatus::Available;
}

int FindBookingIndexByID(unsigned short BookingID,
    vector<stBooking>& vBookings)
{
    for (int i = 0; i < vBookings.size(); i++)
    {
        if (vBookings[i].BookingID == BookingID)
            return i;
    }
    return -1;
}

bool IsBookingExist(unsigned short BookingID,
    vector<stBooking>& vBookings)
{
    return FindBookingIndexByID(BookingID, vBookings) != -1;
}

unsigned short ReadRoomNumber(vector<stRoom>& vRooms)
{
    unsigned short RoomNumber = 0;
    do
    {
        cout << "Enter Room Number: ";
        cin >> RoomNumber;
        if (!IsRoomExist(RoomNumber, vRooms))
            cout << "Room not found! Try again.\n";
    } while (!IsRoomExist(RoomNumber, vRooms));
    return RoomNumber;
}

unsigned short ReadAvailableRoomNumber(vector<stRoom>& vRooms)
{
    unsigned short RoomNumber = 0;
    do
    {
        RoomNumber = ReadRoomNumber(vRooms);
        if (!IsRoomAvailable(RoomNumber, vRooms))
            cout << "Room is already booked! Try again.\n";
    } while (!IsRoomAvailable(RoomNumber, vRooms));
    return RoomNumber;
}
unsigned short GenerateBookingID(vector<stBooking>& vBookings)
{
    return (unsigned short)vBookings.size() + 1;
}

string ReadGuestName()
{
    string Name = "";
    cout << "Enter Guest Name: ";
    cin.ignore();
    getline(cin, Name);
    return Name;
}
int GetCurrentYear()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    return timePtr->tm_year + 1900;
}
bool IsValidDate(string Date)
{
    if (Date.length() != 10)
        return false;

    if (Date[2] != '/' || Date[5] != '/')
        return false;

    for (int i = 0; i < 10; i++)
    {
        if (i == 2 || i == 5) continue;
        if (!isdigit(Date[i]))
            return false;
    }

    int Day = stoi(Date.substr(0, 2));
    int Month = stoi(Date.substr(3, 2));
    int Year = stoi(Date.substr(6, 4));

    if (Month < 1 || Month > 12)
        return false;
    if (Day < 1 || Day > 31)
        return false;
    if (Year < GetCurrentYear())
        return false;

    return true;
}
string ReadDate(string DateType)
{
    string Date = "";
    do
    {
        cout << "Enter " << DateType << " Date (DD/MM/YYYY): ";
        cin >> Date;
        if (!IsValidDate(Date))
            cout << "Invalid Date! Try again.\n";
    } while (!IsValidDate(Date));
    return Date;
}

unsigned short ReadNumberOfNights()
{
    unsigned short Nights = 0;
    do
    {
        cout << "Enter Number of Nights: ";
        cin >> Nights;
    } while (Nights < 1);
    return Nights;
}

stBooking CreateBooking(vector<stRoom>& vRooms,
    vector<stBooking>& vBookings)
{
    stBooking Booking;
    Booking.BookingID = GenerateBookingID(vBookings);

    unsigned short RoomNumber = ReadAvailableRoomNumber(vRooms);
    int Index = FindRoomIndexByNumber(RoomNumber, vRooms);
    Booking.Room = vRooms[Index];

    Booking.GuestName = ReadGuestName();
    Booking.CheckInDate = ReadDate("Check-In");
    Booking.CheckOutDate = ReadDate("Check-Out");
    Booking.NumberOfNights = ReadNumberOfNights();
    Booking.TotalPrice = Booking.Room.PricePerNight *
        Booking.NumberOfNights;

    vRooms[Index].Status = enBookingStatus::Booked;

    return Booking;
}

void AddBooking(vector<stRoom>& vRooms, vector<stBooking>& vBookings)
{
    vBookings.push_back(CreateBooking(vRooms, vBookings));
    cout << "\nBooking Added Successfully!\n";
}


int main()
{
    return 0;
}