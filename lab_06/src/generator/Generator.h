//
// Created by Aleksandr Mikhailov on 01.12.2024.
//
#pragma once
#include <random>

class Npc;

class Generator {
    std::mt19937 generator_;
public:
    Generator();

    std::vector<std::shared_ptr<Npc>> generate_npcies(std::size_t size);
};

