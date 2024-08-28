#include <iostream>
#include "calculate_health.h"

int main() {
    float health;
    std::cout << "Please enter health: ";
    std::cin >> health;
    if (health <= 0) {
        std::cout << "Initial health can not be less or equal 0" << std::endl;
        return 1;
    }
    while (health > 0) {
        float item_distance, item_impact;
        std::cout << "Please enter item distance adn impact using space: ";
        std::cin >> item_distance >> item_impact;
        health = calculate_health(health, item_distance, item_impact);
    }

    std::cout << "You died:(" << std::endl;
    return 0;
}
