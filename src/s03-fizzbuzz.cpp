#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    if (argc == 1) {
        std::cout << "Provide a number in command line." << std::endl;
        return 1;
    }

    auto a = std::stoi(argv[1]);

    for (auto i = 1; i <= a; ++i) {
        std::cout << i << " ";
        if (i % 3 == 0) {
            std::cout << "Fizz";
        }
        if (i % 5 == 0) {
            std::cout << "Buzz";
        }
        std::cout << std::endl;
    }

    return 0;
}
