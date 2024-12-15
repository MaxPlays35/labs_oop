//
// Created by MaxPlays on 07/12/2024.
//
#pragma once
#include <memory>
#include <vector>

#include "../coroutine/Coroutine.h"
#include "../npc/Npc.h"
#include "../randomGenerator/RandomGenerator.h"

class Field {
private:
    const std::size_t sizeX_;
    const std::size_t sizeY_;
    std::vector<std::shared_ptr<Npc>> npcies_;
    RandomGenerator generator_;
public:
    Field(std::size_t sizeX, std::size_t sizeY);

    std::vector<std::shared_ptr<Npc>> & getNpcies();

    std::vector<std::vector<char>> getField() const;

    Coroutine move();

    Coroutine fight();

    void start(std::size_t seconds);

    void load(std::vector<std::shared_ptr<Npc>> npcies);
};
