#include "Time.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

auto Time::to_string() const -> std::string
{
    auto stringstream = std::ostringstream{};
    stringstream << std::setw(2) << std::setfill('0') << this->hour << ":"
                 << std::setw(2) << std::setfill('0') << this->minute << ":"
                 << std::setw(2) << std::setfill('0') << this->second;

    return stringstream.str();
}

auto Time::next_hour() -> void
{
    ++this->hour;
    if (this->hour >= 24) {
        this->hour = 0;
    }
}

auto Time::next_minute() -> void
{
    ++this->minute;
    if (this->minute >= 60) {
        this->minute = 0;
        this->next_hour();
    }
}

auto Time::next_second() -> void
{
    ++this->second;
    if (this->second >= 60) {
        this->second = 0;
        this->next_minute();
    }
}

Time::Time(int h, int m, int s)
{
    if (h >= 24 || m >= 60 || s >= 60) {
        throw std::invalid_argument("Invalid time values.");
    }
    this->hour   = h;
    this->minute = m;
    this->second = s;
}

auto Time::time_of_day() const -> Time::Time_of_day
{
    if (this->hour >= 4 && this->hour < 12) {
        return Time::Time_of_day::MORNING;
    } else if (this->hour >= 12 && this->hour < 17) {
        return Time::Time_of_day::DAY;
    } else if (this->hour >= 17 && this->hour < 22) {
        return Time::Time_of_day::EVENING;
    } else {
        return Time::Time_of_day::NIGHT;
    }
}

auto Time::to_string(Time::Time_of_day d) const -> std::string
{
    switch (d) {
    case Time::Time_of_day::MORNING:
        return "morning";

    case Time::Time_of_day::DAY:
        return "day";

    case Time::Time_of_day::EVENING:
        return "evening";

    case Time::Time_of_day::NIGHT:
        return "night";

    default:
        throw std::invalid_argument{"Invalid time of a day."};
    }
}

auto Time::operator+(Time const& t2) const -> Time
{
    auto h = this->hour + t2.hour;
    auto m = this->minute + t2.minute;
    auto s = this->second + t2.second;
    if (s > 59) {
        s -= 60;
        ++m;
    }
    if (m > 59) {
        m -= 60;
        ++h;
    }
    if (h > 23) {
        h -= 24;
    }

    return Time{h, m, s};
}

auto Time::operator-(Time const& t2) const -> Time
{
    auto h = this->hour - t2.hour;
    auto m = this->minute - t2.minute;
    auto s = this->second - t2.second;
    if (s < 0) {
        s += 60;
        --m;
    }
    if (m < 0) {
        m += 60;
        --h;
    }
    if (h < 0) {
        h += 24;
    }
    return Time{h, m, s};
}

auto Time::operator<(Time const& t2) const -> bool
{
    return this->hour < t2.hour || this->minute < t2.minute
           || this->second < t2.second;
}

auto Time::operator>(Time const& t2) const -> bool
{
    return this->hour > t2.hour || this->minute > t2.minute
           || this->second > t2.second;
}

auto Time::operator==(Time const& t2) const -> bool
{
    return this->hour == t2.hour || this->minute == t2.minute
           || this->second == t2.second;
}

auto Time::operator!=(Time const& t2) const -> bool
{
    return this->hour != t2.hour || this->minute != t2.minute
           || this->second != t2.second;
}

auto Time::count_seconds() const -> uint64_t
{
    return this->hour * 3600 + this->minute * 60 + this->second;
}

auto Time::count_minutes() const -> uint64_t
{
    return this->hour * 60 + this->minute;
}

auto Time::time_to_midnight() const -> Time
{
    return Time{0, 0, 0} - *this;
}

auto main() -> int
{
    auto time  = Time{23, 59, 59};
    auto time2 = Time{20, 56, 50};

    std::cout << time.to_string() << std::endl;
    time.next_second();
    std::cout << time.to_string() << std::endl;
    time.next_minute();
    std::cout << time.to_string() << std::endl;
    time.next_hour();
    std::cout << time.to_string() << std::endl << std::endl;

    std::cout << time.to_string(Time::Time_of_day::MORNING) << std::endl
              << time.to_string(Time::Time_of_day::DAY) << std::endl
              << time.to_string(Time::Time_of_day::EVENING) << std::endl
              << time.to_string(Time::Time_of_day::NIGHT) << std::endl
              << std::endl;

    auto time3 = time + time2;
    std::cout << time.to_string() << " + " << time2.to_string() << " = "
              << time3.to_string() << std::endl
              << "Good " << time3.to_string(time3.time_of_day()) << " to you!"
              << std::endl;

    time3 = time - time2;
    std::cout << time.to_string() << " - " << time2.to_string() << " = "
              << time3.to_string() << std::endl
              << "Good " << time3.to_string(time3.time_of_day()) << " to you!"
              << std::endl
              << std::endl;

    std::cout << time.to_string() << " < " << time2.to_string() << " = "
              << std::boolalpha << (time < time2) << std::endl;
    std::cout << time.to_string() << " > " << time2.to_string() << " = "
              << std::boolalpha << (time > time2) << std::endl;
    std::cout << time.to_string() << " == " << time2.to_string() << " = "
              << std::boolalpha << (time == time2) << std::endl;
    std::cout << time.to_string() << " != " << time2.to_string() << " = "
              << std::boolalpha << (time != time2) << std::endl
              << std::endl;

    std::cout << "It's " << time.to_string() << " It's " << time.count_seconds()
              << " seconds from midnight!" << std::endl;
    std::cout << "It's " << time2.to_string() << " It's "
              << time2.count_seconds() << " seconds from midnight!" << std::endl
              << std::endl;

    std::cout << "It's " << time.to_string() << " It's " << time.count_minutes()
              << " minutes from midnight!" << std::endl;
    std::cout << "It's " << time2.to_string() << " It's "
              << time2.count_minutes() << " minutes from midnight!" << std::endl
              << std::endl;

    std::cout << "It's " << time.to_string() << " It's "
              << time.time_to_midnight().to_string() << " to midnight!"
              << std::endl;
    std::cout << "It's " << time2.to_string() << " It's "
              << time2.time_to_midnight().to_string() << " to midnight!"
              << std::endl;
    return 0;
}
