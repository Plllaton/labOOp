#include <memory>
#include <iostream>
#include <vector>
#include <string>

class Inventory {
private:
    std::vector<std::unique_ptr<std::string>> items;

public:
    void addItem(const std::string& item) {
        items.push_back(std::make_unique<std::string>(item));
    }

    void displayInventory() const {
        std::cout << "Inventory:\n";
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << "  " << i + 1 << ": " << *items[i] << "\n";
        }
    }
};

int main() {
    Inventory playerInventory;
    playerInventory.addItem("Sword");
    playerInventory.addItem("Bow");
    playerInventory.displayInventory();

    return 0;
}
