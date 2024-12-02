//
// Created by Aleksandr Mikhailov on 30.11.2024.
//

#include "Bear.h"

Bear::Bear(std::string name, bool isAlive, int x, int y) : Npc(BearType, name, isAlive, x, y) {
}

Bear::Bear(std::istream & is) : Npc(BearType, is) {
}

bool Bear::accept(std::shared_ptr<Npc> visitor) {
    return visitor->fight(std::shared_ptr<Bear>(this, [](const Bear* p) {}));;
}

bool Bear::fight(std::shared_ptr<Squirrel> other) {
    fightNotify(other, true);
    other->kill();
    return true;
}

bool Bear::fight(std::shared_ptr<Bear> other) {
    fightNotify(other, false);
    return false;
}

bool Bear::fight(std::shared_ptr<Orc> other) {
    fightNotify(other, false);
    return false;
}

void Bear::print() {
    std::cout << "Bear(" <<  name_ << ", " <<  isAlive_ << ", " << x_ << ", " << y_ << ')' << std::endl;
}

void Bear::save(std::ostream &os) {
    os << BearType << std::endl;
    Npc::save(os);
}


