#include <iostream>
#include <string>

auto main(int argc, char* argv[]) -> int
{
    auto bottles = 99;
    if (argc > 1) {
        bottles = std::stoi(argv[1]);
        if (bottles < 0) {
            std::cout << "Why so negative, here is a beer... (Provide positive "
                         "number.)"
                      << std::endl;
            return 1;
        }
    }
    for (auto i = bottles; i > 0; --i) {
        std::cout << i << " bottles of beer on the wall, " << i
                  << " bottles of beer." << std::endl
                  << "Take one down, pass it around, " << i - 1
                  << " bottles of beer on the wall..." << std::endl;
    }
    std::cout << "No more bottles of beer on the wall, no more bottles of beer."
              << std::endl
              << "Go to the store and buy some more, " << bottles
              << " bottles of beer on the wall..." << std::endl;

    return 0;
}
