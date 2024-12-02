//
// Created by MaxPlays on 29/11/2024.
//
#pragma once
#include <memory>
#include <vector>

#include "../consts/consts.h"

class IObserver;
class Orc;
class Squirrel;
class Bear;

class Npc : public std::enable_shared_from_this<Npc>{
protected:
    NpcType type_;
    std::string name_;
    bool isAlive_ = true;
    int x_ = 0;
    int y_ = 0;
    std::vector<std::shared_ptr<IObserver>> observers_;

public:
    Npc(NpcType type, std::string name, bool isAlive, int x, int y);

    Npc(NpcType type, std::istream & is);

    Npc(const Npc & other) = default;

    Npc(Npc && other) noexcept = default;

    void subscribe(std::shared_ptr<IObserver> observer);

    void fightNotify(const std::shared_ptr<Npc> defender, bool win);

    bool isClose(std::shared_ptr<Npc> other, std::size_t distance) const;

    void kill();

    bool isAlive() const;

    virtual bool accept(std::shared_ptr<Npc> visitor) = 0;

    virtual bool fight(std::shared_ptr<Orc> other) = 0;

    virtual bool fight(std::shared_ptr<Squirrel> other) = 0;

    virtual bool fight(std::shared_ptr<Bear> other) = 0;

    virtual void print() = 0;

    virtual void save(std::ostream & os);

    virtual bool operator==(const Npc & other) const;

    virtual ~Npc() = default;
};
