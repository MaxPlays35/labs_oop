//
// Created by MaxPlays on 29/11/2024.
//
#pragma once
#include <memory>
#include "../npc/Npc.h"

class IObserver {
public:
    virtual ~IObserver() = default;

    virtual void onFight(std::shared_ptr<Npc> attacker, std::shared_ptr<Npc> defender, bool win) = 0;
};
