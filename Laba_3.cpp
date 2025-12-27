#include <iostream>
#include <string>


class Weapon {
private:
    std::string name;
    int damage;

public:
    Weapon(const std::string& n, int d)
        : name(n), damage(d) {
    }

    Weapon operator+(const Weapon& other) const {
        return Weapon(name + " + " + other.name, damage + other.damage);
    }

    bool operator>(const Weapon& other) const {
        return damage > other.damage;
    }

    friend std::ostream& operator<<(std::ostream& os, const Weapon& Weapon) {
        os << "Weapon: " << Weapon.name << ", Damage: " << Weapon.damage;
        return os;
    }
};

int main() {
    Weapon sword("Sword", 60);
    Weapon bow("Bow", 25);
    std::cout << bow << std::endl;
    std::cout << sword << std::endl;
    std::cout << sword + bow << std::endl;

    if (sword > bow) {
        std::cout << "Sword has more damage!\n";
    }
    else {
        std::cout << "Bow has more damage!\n";
    }
    return 0;
}
