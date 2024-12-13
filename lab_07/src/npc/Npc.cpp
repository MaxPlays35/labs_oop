//
// Created by MaxPlays on 29/11/2024.
//

#include <istream>
#include "Npc.h"
#include "../observer/IObserver.h"

Npc::Npc(NpcType type, std::string name, bool isAlive, int x, int y) : type_(type), name_(std::move(name)),
                                                                       isAlive_(isAlive), x_(x), y_(y) {
}

Npc::Npc(NpcType type, std::istream & is) : type_(type) {
    is >> name_;
    is >> isAlive_;
    is >> x_;
    is >> y_;
}

void Npc::subscribe(std::shared_ptr<IObserver> observer) {
    observers_.push_back(observer);
}

void Npc::fightNotify(const std::shared_ptr<Npc> defender, bool win) {
    for (const auto & observer : observers_) {
        observer->onFight(shared_from_this(), defender, win);
    }
}

bool Npc::isClose(std::shared_ptr<Npc> other, const std::size_t distance) const {
    return ((x_ - other->x_) * (x_ - other->x_) + (y_ - other->y_) * (y_ - other->y_)) <= distance * distance;
}

void Npc::kill() {
    isAlive_  = false;
}

bool Npc::isAlive() const {
    return isAlive_;
}

std::pair<int, int> Npc::position() const {
    return std::make_pair(x_, y_);
}

NpcType Npc::getType() const {
    return type_;
}

void Npc::move(int x, int y) {
    x_ = x;
    y_ = y;
}

void Npc::save(std::ostream & os) {
    os << name_ << std::endl;
    os << isAlive_ << std::endl;
    os << x_ << std::endl;
    os << y_ << std::endl;
}

bool Npc::operator==(const Npc &other) const {
    return type_ == other.type_ and name_ == other.name_ and
            isAlive_ == other.isAlive_ and x_ == other.x_ and y_ == other.y_;
}
