//
// Created by mikhail on 28.08.24.
//
// calculate_health.cpp
#include "calculate_health.h"

float calculate_health(float health, float item_distance, float item_impact) {
    if (item_distance <= 100) {
        health += item_impact * (1 - item_distance/100);
    }

    if (health > 0 && health < 1) {
        health = 1;
    }

    return health;
}
