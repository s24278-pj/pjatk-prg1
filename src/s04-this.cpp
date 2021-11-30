#include "this.h"

#include <iostream>
#include <string>

Hero::Hero(std::string const n, Class c, int s, int d, int i)
        : name{n}, cl{c}, strength{s}, dexterity{d}, inteligence{i}
{}

auto Hero::value_this() const -> void
{
    std::cout << this << std::endl;
    std::cout << &this->name << std::endl;
    std::cout << &this->cl << std::endl;
    std::cout << &this->strength << std::endl;
    std::cout << &this->dexterity << std::endl;
    std::cout << &this->inteligence << std::endl;
}

auto main() -> int
{
    auto hero1 = Hero{"Dakrana", Hero::Class::ROGUE, 14, 20, 12};
    auto hero2 = Hero{"Brahma", Hero::Class::FIGHTER, 20, 14, 9};
    auto hero3 = Hero{"Luven", Hero::Class::WIZARD, 8, 10, 20};

    std::cout << hero1.name << std::endl;
    hero1.value_this();
    std::cout << "vs" << std::endl
              << &hero1 << std::endl
              << &hero1.name << std::endl
              << &hero1.cl << std::endl
              << &hero1.strength << std::endl
              << &hero1.dexterity << std::endl
              << &hero1.inteligence << std::endl
              << std::endl;

    std::cout << hero2.name << std::endl;
    hero2.value_this();
    std::cout << "vs" << std::endl
              << &hero2 << std::endl
              << &hero2.name << std::endl
              << &hero2.cl << std::endl
              << &hero2.strength << std::endl
              << &hero2.dexterity << std::endl
              << &hero2.inteligence << std::endl
              << std::endl;

    std::cout << hero3.name << std::endl;
    hero3.value_this();
    std::cout << "vs" << std::endl
              << &hero3 << std::endl
              << &hero3.name << std::endl
              << &hero3.cl << std::endl
              << &hero3.strength << std::endl
              << &hero3.dexterity << std::endl
              << &hero3.inteligence << std::endl
              << std::endl;

    return 0;
}