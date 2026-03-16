# 🏨 Hotel Booking System — C++

A console-based Hotel Booking System built in **C++** demonstrating
core concepts of **Functional & Procedural Programming**.

---

## 🎯 Learning Objectives

- Structuring a program using functions (Procedural Programming)
- Using `vector` to manage dynamic lists
- File I/O — save and load data from files
- Exception handling and input validation
- Using `enum` for clean code readability
- String manipulation with `substr` and `stoi`
- Date validation with `<ctime>`

---

## 🕹️ Features

- 📋 View all available rooms
- 🛏️ Book a room with guest details
- ❌ Cancel an existing booking
- 📄 View all bookings
- 🧾 Print invoice for any booking
- 💾 Auto-save bookings to file

---

## 🏗️ Project Architecture

```
main()
 └── RunHotelSystem()
      ├── LoadRoomList()
      ├── LoadBookingsFromFile()
      └── Menu Loop
           ├── PrintRoomList()
           ├── AddBooking()
           │    ├── ReadAvailableRoomNumber()
           │    ├── ReadGuestName()
           │    ├── ReadDate()
           │    │    └── IsValidDate()
           │    │         └── GetCurrentYear()
           │    └── ReadNumberOfNights()
           ├── CancelBooking()
           │    └── PrintBookingList()
           ├── ShowInvoice()
           │    └── PrintInvoice()
           └── SaveBookingsToFile()
```

---

## 💡 Key Concepts

| Concept          | Where in Code                                       |
| ---------------- | --------------------------------------------------- |
| Enums            | `enRoomType`, `enBookingStatus`, `enMainMenuChoice` |
| Structs          | `stRoom`, `stBooking`                               |
| Vectors          | `vRooms`, `vBookings`                               |
| File I/O         | `SaveBookingsToFile()`, `LoadBookingsFromFile()`    |
| Date Validation  | `IsValidDate()`, `GetCurrentYear()`                 |
| String Methods   | `substr()`, `stoi()`, `stod()`                      |
| Search Functions | `FindRoomIndexByNumber()`, `FindBookingIndexByID()` |

---

## 🔧 Build & Run

**Open in Visual Studio**

```
double click: hotel-booking-cpp.slnx
Ctrl + F5
```

**Windows (MinGW / g++)**

```bash
g++ hotel-booking-cpp.cpp -o hotel.exe
./hotel.exe
```

---

## 📁 File Structure

```
hotel-booking-cpp/
├── .gitignore
├── README.md
├── LICENSE
├── hotel-booking-cpp.slnx
└── hotel-booking-cpp/
    ├── hotel-booking-cpp.cpp
    ├── hotel-booking-cpp.vcxproj
    └── hotel-booking-cpp.vcxproj.filters
```

> 📝 `Bookings.txt` is auto-generated when you add your first booking.
> It is excluded from version control via `.gitignore`.

---

## 👤 Author

Built as a learning exercise in C++ Procedural Programming.

---

## 📄 License

MIT License
