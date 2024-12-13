//
// Created by MaxPlays on 14/12/2024.
//

#include "RandomGenerator.h"

int RandomGenerator::generateInt(int min, int max) {
    std::uniform_int_distribution<int> distribution(min,max);
    return distribution(generator_);
}
