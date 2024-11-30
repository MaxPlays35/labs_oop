//
// Created by MaxPlays on 29/11/2024.
//
#pragma once
#include <memory>
#include <vector>

#include "../consts/consts.h"

class IObserver;

class Npc : std::enable_shared_from_this<Npc>{
private:
    NpcType type_;
    std::string name_;
    bool isAlive_ = true;
    int x_ = 0;
    int y_ = 0;
    std::vector<std::shared_ptr<IObserver>> observers_;

public:
    Npc() = default;

    Npc(NpcType type, std::string name, bool isAlive, int x, int y);

    Npc(const Npc & other);

    Npc(Npc && other) noexcept;

    void subscribe(std::shared_ptr<IObserver> observer);

    void fightNotify(std::shared_ptr<Npc> defender, bool win);

    // virtual bool

    virtual void print() = 0;


    ~Npc() = default;
};
