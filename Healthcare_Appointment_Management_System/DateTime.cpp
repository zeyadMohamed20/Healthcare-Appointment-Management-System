#include "DateTime.h"
#include <chrono>
#include <iostream>
#include <iomanip>

using namespace std;

DateTime::DateTime() {
    auto now = chrono::system_clock::now();
    time_t now_time_t = chrono::system_clock::to_time_t(now);
    localtime_s(&timeInfo, &now_time_t); // Use localtime_s for safer conversion
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int second) {
    timeInfo.tm_year = year - 1900;
    timeInfo.tm_mon = month - 1;
    timeInfo.tm_mday = day;
    timeInfo.tm_hour = hour;
    timeInfo.tm_min = minute;
    timeInfo.tm_sec = second;
}

void DateTime::print() const {
    cout << put_time(&timeInfo, "%Y-%m-%d %H:%M:%S") << endl;
}

// Getter for timeInfo
tm DateTime::getTimeInfo() const {
    return timeInfo;
}

// Setter for timeInfo
void DateTime::setTimeInfo(const tm& newTimeInfo) {
    timeInfo = newTimeInfo;
}

bool DateTime::operator==(const DateTime& other) const 
{
    return (timeInfo.tm_year == other.timeInfo.tm_year &&\
        timeInfo.tm_mon == other.timeInfo.tm_mon &&\
        timeInfo.tm_mday == other.timeInfo.tm_mday &&\
        timeInfo.tm_hour == other.timeInfo.tm_hour &&\
        timeInfo.tm_min == other.timeInfo.tm_min &&\
        timeInfo.tm_sec == other.timeInfo.tm_sec);
}
