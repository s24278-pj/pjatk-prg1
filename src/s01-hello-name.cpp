#include <iostream>

auto main(int argc, char* argv[]) -> int
{
    if (argc == 1) {
        std::cout << "Provide name as argument in command line." << std::endl;
        return 1;
    }

    auto const name = std::string{argv[1]};
    std::cout << "Hello, " << name << "!" << std::endl;

    return 0;
}
