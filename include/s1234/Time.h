#include <string>

struct Time {
    int hour{};
    int minute{};
    int second{};
    enum class Time_of_day {
        MORNING,
        DAY,
        EVENING,
        NIGHT,
    };

    auto to_string() const -> std::string;
    auto time_of_day() const -> Time_of_day;
    auto to_string(Time_of_day d) const -> std::string;
    auto next_hour() -> void;
    auto next_minute() -> void;
    auto next_second() -> void;

    auto operator+(Time const& t2) const -> Time;
    auto operator-(Time const& t2) const -> Time;
    auto operator<(Time const& t2) const -> bool;
    auto operator>(Time const& t2) const -> bool;
    auto operator==(Time const& t2) const -> bool;
    auto operator!=(Time const& t2) const -> bool;

    auto count_seconds() const -> uint64_t;
    auto count_minutes() const -> uint64_t;
    auto time_to_midnight() const -> Time;

    Time() = default;
    Time(int h, int m, int s);
};
