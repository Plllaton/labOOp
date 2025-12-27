#include <iostream>
#include <string>

class Character {
private:
    std::string name;  // Имя персонажа
    int health;        // Уровень здоровья
    int attack;        // Уровень атаки
    int defense;       // Уровень защиты

public:
    Character(const std::string& n, int h, int a, int d)
        : name(n), health(h), attack(a), defense(d) {
    }

    int getHealth() const {
        return health;
    }

    void heal(int amount) {
        health += amount;
        if (health > 100) { health = 100; }
        std::cout << name << " healed, health: " << health << std::endl;
    }

    void takeDamage(int amount) {
        health -= amount;
        if (health < 0) { health = 0; }
        std::cout << name << " damaged, health: " << health << std::endl;
    }

    void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attack << ", Defense: " << defense << std::endl;
    }

    void attackEnemy(Character& enemy) {
        int damage = attack - enemy.defense;
        if (damage > 0) {
            enemy.health -= damage;
            std::cout << name << " attacks " << enemy.name << " for " << damage << " damage!" << std::endl;
        }
        else {
            std::cout << name << " attacks " << enemy.name << ", but it has no effect!" << std::endl;
        }
    }
};

int main() {
    Character hero("Hero", 100, 20, 10);
    Character monster("Goblin", 50, 15, 5);

    hero.displayInfo();
    monster.displayInfo();

    hero.takeDamage(30);
    hero.heal(20);
    hero.takeDamage(100);

    hero.attackEnemy(monster);
    monster.displayInfo();

    hero.displayInfo();

    return 0;
}
