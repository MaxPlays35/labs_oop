//
// Created by Aleksandr Mikhailov on 30.11.2024.
//
#pragma once
#include "../npc/Npc.h"

class Squirrel : public Npc {
public:
    Squirrel(std::string name, bool isAlive, int x, int y);

    explicit Squirrel(std::istream & is);

    bool accept(std::shared_ptr<Npc> visitor) override;

    bool fight(std::shared_ptr<Squirrel> other) override;

    bool fight(std::shared_ptr<Bear> other) override;

    bool fight(std::shared_ptr<Orc> other) override;

    void print() override;

    void save(std::ostream &os) override;
};
