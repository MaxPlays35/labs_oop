//
// Created by MaxPlays on 14/12/2024.
//
#pragma once
#include <random>

class RandomGenerator {
private:
    std::mt19937 generator_;
public:
    RandomGenerator() = default;

    int generateInt(int min, int max);
};
