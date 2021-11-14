#include <chrono>
#include <iostream>
#include <string>
#include <thread>

auto main(int, char* argv[]) -> int
{
    if (argv[1] == 0) {
        std::cout << "Please provide number in command line." << std::endl;
        return 1;
    }

    int counter = std::stoi(argv[1]);

    for (auto i = counter; i >= 0; --i) {
        std::cout << i << "..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "Done!" << std::endl;

    return 0;
}
