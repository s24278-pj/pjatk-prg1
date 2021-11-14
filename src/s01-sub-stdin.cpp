#include <iostream>
#include <string>

auto ask_user_for_integer(std::string prompt) -> float
{
    std::cout << "Float number:" << prompt;
    auto n = std::string{};
    std::getline(std::cin, n);
    return std::stof(n);
}

auto main() -> int
{
    auto const a = ask_user_for_integer(" a = ");
    auto const b = ask_user_for_integer(" b = ");
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    return 0;
}
