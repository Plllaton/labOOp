#include <iostream>
#include <string>

class Entity {
protected:
    std::string name;   // имя
    int health;      // здоровье

public:
    Entity(const std::string& n, int h) : name(n), health(h) {}

    virtual void displayInfo() const {
        std::cout << "Name: " << name << ", HP: " << health << std::endl;
    }

    virtual ~Entity() {}
};

class Player : public Entity {
private:
    int experience; // опыт

public:
    Player(const std::string& n, int h, int exp)
        : Entity(n, h), experience(exp) {
    }

    void displayInfo() const override {
        Entity::displayInfo();
        std::cout << "Experience: " << experience << std::endl;
    }
};

class Enemy : public Entity {
private:
    std::string type; // тип врага

public:
    Enemy(const std::string& n, int h, const std::string& t)
        : Entity(n, h), type(t) {
    }

    void displayInfo() const override {
        Entity::displayInfo();
        std::cout << "Type: " << type << std::endl;
    }
};

class Boss : public Enemy {
private:
    std::string specialAbility;

public:
    Boss(const std::string& n, int h, const std::string& t, const std::string& sA)
        : Enemy(n, h, t), specialAbility(sA) {
    }

    void displayInfo() const override {
        Enemy::displayInfo();
        std::cout << "Special ability: " << specialAbility << std::endl;
    }
};

int main() {
    Player hero("Hero", 100, 0);
    Enemy monster("Goblin", 50, "Goblin");
    Boss boss("Orc", 300, "Boss", "Kills with one hit");

    hero.displayInfo();
    monster.displayInfo();
    boss.displayInfo();

    return 0;
}
