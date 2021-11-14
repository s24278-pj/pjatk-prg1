#include <iostream>
#include <map>
#include <random>
#include <string>

auto guess(std::string prompt) -> int
{
    auto g = std::string{};
    std::cout << prompt;
    std::getline(std::cin, g);
    return std::stoi(g);
}

auto main() -> int
{
    std::random_device rd;
    std::uniform_int_distribution<int> d100(1, 100);

    auto const right = d100(rd);
    auto picked      = 0;

    do {
        picked = guess("guess: ");

        if (picked < right) {
            std::cout << "number too small! " << std::endl;
        } else if (picked > right) {
            std::cout << "number too big! " << std::endl;
        }

    } while (picked != right);

    std::cout << "just right! " << std::endl;

    return 0;
}
