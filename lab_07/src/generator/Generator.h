//
// Created by Aleksandr Mikhailov on 01.12.2024.
//
#pragma once
#include <memory>
#include <random>

#include "../randomGenerator/RandomGenerator.h"

class Npc;

class Generator {
    RandomGenerator generator_;
public:
    Generator();

    std::vector<std::shared_ptr<Npc>> generateNpcies(std::size_t size, std::size_t xMax = 100, std::size_t yMax = 100);
};

