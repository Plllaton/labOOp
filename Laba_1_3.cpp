
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Entity {
protected:
    string name;
    int health;
    int attackPower;
    int defense;

public:
    Entity(const string& n, int h, int a, int d)
        : name(n), health(h), attackPower(a), defense(d) {
    }

    string getName() const { return name; }
    int getHealth() const { return health; }
    int getDefense() const { return defense; }

    void reduceHealth(int amount) { health -= amount; }

    virtual void attack(Entity& target) {
        int damage = attackPower - target.defense;
        if (damage > 0) {
            target.health -= damage;
            std::cout << name << " attacks " << target.name << " for " << damage << " damage!\n";
        }
        else {
            std::cout << name << " attacks " << target.name << ", but it has no effect!\n";
        }
    }

    virtual void heal(int amount) {
        cout << name << "can't heals";
    }

    virtual void displayInfo() const {
        cout << "Name: " << name << ", HP: " << health
            << ", Attack: " << attackPower << ", Defense: " << defense << endl;
    }
};

class Character : public Entity {
public:
    Character(const string& n, int h, int a, int d)
        : Entity(n, h, a, d) {
    }

    void attack(Entity& target) override {
        int damage = attackPower - target.getDefense();
        if (damage > 0) {
            if (rand() % 100 < 20) { // Критический удар (20%)
                damage *= 2;
                cout << "Critical hit! ";
            }
            target.reduceHealth(damage);
            cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
        }
        else {
            cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
        }
    }

    void heal(int amount) override {
        health += amount;
        if (health > 100) {
            health = 100;
        }
        cout << name << "`s health: " << amount << "\n";
    }

    void displayInfo() const override {
        cout << "Character: " << name << ", HP: " << health
            << ", Attack: " << attackPower << ", Defense: " << defense << endl;
    }
};

class Monster : public Entity {
public:
    Monster(const string& n, int h, int a, int d)
        : Entity(n, h, a, d) {
    }

    void attack(Entity& target) override {
        int damage = attackPower - target.getDefense();
        if (damage > 0) {
            if (rand() % 100 < 30) { // Ядовитая атака (30%)
                damage += 5;
                cout << "Poisonous attack! ";
            }
            target.reduceHealth(damage);
            cout << name << " attacks " << target.getName() << " for " << damage << " damage!\n";
        }
        else {
            cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
        }
    }

    void displayInfo() const override {
        cout << "Monster: " << name << ", HP: " << health
            << ", Attack: " << attackPower << ", Defense: " << defense << endl;
    }
};

class Boss : public Monster {
public:
    Boss(const string& n, int h, int a, int d)
        : Monster(n, h, a, d) {
    }

    void attack(Entity& target) override {
        int damage = attackPower - target.getDefense();
        if (damage > 0) {
            if (rand() % 100 < 40) { 
                damage += 10;
                cout << "Thunder strike! ";
            }
            target.reduceHealth(damage);
            cout << name << " powerful attacks " << target.getName() << " for " << damage << " damage!\n";
        }
        else {
            cout << name << " attacks " << target.getName() << ", but it has no effect!\n";
        }
    }

    void displayInfo() const override {
        cout << "Boss: " << name << ", HP: " << health
            << ", Attack: " << attackPower << ", Defense: " << defense << endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    Character hero("Hero", 100, 20, 10);
    Monster goblin("Goblin", 50, 15, 5);
    Boss dragon("Dragon", 100, 30, 15);

    Entity* entities[] = { &hero, &goblin, &dragon };

    for (auto& entity : entities) {
        entity->displayInfo();
    }

    hero.attack(goblin);
    goblin.attack(hero);
    dragon.attack(hero);

    cout << "\nHero decides to heal...\n";
    hero.heal(30);

    cout << "\nUpdated Stats:\n";
    for (auto& entity : entities) {
        entity->displayInfo();
    }

    return 0;
}
