#include <iostream>
#include <string>

auto get_pass(std::string prompt) -> std::string
{
    auto a = std::string{};
    std::cout << prompt;
    std::getline(std::cin, a);

    return a;
}

auto main(int argc, char* argv[]) -> int
{
    if (argc == 1) {
        std::cout << "Provide correct password" << std::endl;
        return 1;
    }

    auto const wanted_password = std::string{argv[1]};
    auto pass                  = std::string{};

    do {
        pass = get_pass("password: ");
    } while (wanted_password != pass);
    std::cout << "Password correct!" << std::endl;

    return 0;
}
