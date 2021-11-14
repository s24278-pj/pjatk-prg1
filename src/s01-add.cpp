#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    if (argc == 1) {
        std::cout << "Two numeric arguments needed to run the program."
                  << std::endl;
        return 1;
    }

    auto const a = std::stoi(argv[1]);
    auto const b = std::stoi(argv[2]);
    std::cout << (a + b) << std::endl;
    return 0;
}
