#include <string>

struct Student {
    std::string const name{};
    std::string const surname{};
    std::string const index{};
    int year{};
    enum class Semester {
        SPRING,
        WINTER,
    };
    Semester semester{Semester::SPRING};

    double average{};

    auto to_string() const -> std::string;

    Student() = default;
    Student(std::string const n,
            std::string const s,
            std::string const i,
            int y,
            Semester semester,
            double a);
};
