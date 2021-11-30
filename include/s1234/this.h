#include <string>

struct Hero {
    std::string const name;

    enum class Class {
        FIGHTER,
        ROGUE,
        WIZARD,
    };
    Class cl{Class::FIGHTER};

    int strength;
    int dexterity;
    int inteligence;

    auto value_this() const -> void;

    Hero() = default;
    Hero(std::string const n, Class c, int s, int d, int i);
};