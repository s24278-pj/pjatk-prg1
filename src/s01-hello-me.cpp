#include <iostream>

auto main() -> int
{
    std::cout << "Student name: ";

    auto name = std::string{};

    do {
        std::getline(std::cin, name);
        if (name.empty()) {
            std::cout << "Provide student name: ";
        } else {
            std::cout << "Hello, " << name << "!" << std::endl;
        }
    } while (name.empty());


    return 0;
}
