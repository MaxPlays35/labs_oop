//
// Created by Aleksandr Mikhailov on 30.11.2024.
//

#include "Orc.h"

#include <iostream>

#include "../bear/Bear.h"
#include "../printer/Printer.h"
#include "../squirrel/Squirrel.h"

Orc::Orc(std::string name, bool isAlive, int x, int y) : Npc(OrcType, name, isAlive, x, y) {
}

Orc::Orc(std::istream & is) : Npc(OrcType, is) {
}

bool Orc::accept(std::shared_ptr<Npc> visitor) {
    return visitor->fight(std::shared_ptr<Orc>(this, [](const Orc* p) {}));
}

bool Orc::fight(std::shared_ptr<Squirrel> other) {
    fightNotify(other, false);
    return false;
}

bool Orc::fight(std::shared_ptr<Bear> other) {
    fightNotify(other, true);
    other->kill();
    return true;
}

bool Orc::fight(std::shared_ptr<Orc> other) {
    fightNotify(other, true);
    other->kill();
    return true;
}

void Orc::print() {
    printer << "Orc(" <<  name_ << ", " <<  isAlive_ << ", " << x_ << ", " << y_ << ')' << std::endl;
}

void Orc::save(std::ostream &os) {
    os << OrcType << std::endl;
    Npc::save(os);
}

bool Orc::isClose(std::shared_ptr<Npc> other) const {
    return Npc::isClose(other, 10);
}






