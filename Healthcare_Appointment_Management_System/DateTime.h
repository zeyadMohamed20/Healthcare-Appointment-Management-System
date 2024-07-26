#pragma once

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

class DateTime {
private:
    tm timeInfo;

public:
    DateTime();
    DateTime(int year, int month, int day, int hour, int minute, int second);

    void print() const;

    // Getter for timeInfo
    tm getTimeInfo() const;

    // Setter for timeInfo
    void setTimeInfo(const tm& newTimeInfo);

    bool operator==(const DateTime& other) const;
};
