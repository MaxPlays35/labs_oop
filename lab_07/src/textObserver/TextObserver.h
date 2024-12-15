//
// Created by MaxPlays on 29/11/2024.
//
#pragma once
#include "../observer/IObserver.h"


class TextObserver : public IObserver{
public:
    static std::shared_ptr<IObserver> get();

    void onFight(std::shared_ptr<Npc> attacker, std::shared_ptr<Npc> defender, bool win) override;
};
