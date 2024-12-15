//
// Created by Aleksandr Mikhailov on 30.11.2024.
//
#pragma once
#include "../npc/Npc.h"
#include "../squirrel/Squirrel.h"
#include "../orc//Orc.h"

class Bear : public Npc {
public:
    Bear(std::string name, bool isAlive, int x, int y);

    explicit Bear(std::istream & is);

    bool accept(std::shared_ptr<Npc> visitor) override;

    bool fight(std::shared_ptr<Squirrel> other) override;

    bool fight(std::shared_ptr<Bear> other) override;

    bool fight(std::shared_ptr<Orc> other) override;

    void print(std::stringstream & stream) override;

    void save(std::ostream &os) override;

    bool isClose(std::shared_ptr<Npc> other) const override;
};
