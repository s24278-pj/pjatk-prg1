#include "Student.h"

#include <iostream>
#include <string>

auto enum_convert(Student::Semester semester) -> std::string
{
    switch (semester) {
    case Student::Semester::SPRING:
        return "SPRING";

    case Student::Semester::WINTER:
        return "WINTER";

    default:
        throw std::invalid_argument{"Invalid semester."};
    }
}

auto Student::to_string() const -> std::string
{
    return ("Student: " + this->name + " " + this->surname + "\n"
            + "Index number: " + this->index + "\n"
            + "Year: " + std::to_string(this->year)
            + " Semester: " + enum_convert(this->semester) + "\n"
            + "Average: " + std::to_string(this->average));
}

Student::Student(std::string const n,
                 std::string const s,
                 std::string const i,
                 int y,
                 Student::Semester semester,
                 double a)
        : name{n}, surname{s}, index{i}, year{y}, semester{semester}, average{a}
{}

auto main() -> int
{
    auto Honorata_Wisniewska = Student{
        "Honorata", "Wisniewska", "24278", 1, Student::Semester::SPRING, 4.5};
    std::cout << Honorata_Wisniewska.to_string() << std::endl;
    return 0;
}