#include <iostream>
#include <string>
#include <thread>

struct Hero {
    std::string const name;

    Hero() = default;
    Hero(std::string n) : name{n}
    {}

    ~Hero()
    {
        std::cout << "FIREBALL!" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "DESTRUCTION! Say hello to " << this->name << "!"
                  << std::endl;
    }
};


auto main() -> int
{
    {
        auto hero2 = Hero{"NIXIE"};
        std::cout << "Oh! Who is that?" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    auto hero1 = Hero{"DRAGON"};
    std::cout << "Oh! Who is that?" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));

    return 0;
}