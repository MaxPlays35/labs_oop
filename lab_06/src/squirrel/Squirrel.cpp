//
// Created by Aleksandr Mikhailov on 30.11.2024.
//

#include "Squirrel.h"

#include "../bear/Bear.h"
#include "../orc/Orc.h"

Squirrel::Squirrel(std::string name, bool isAlive, int x, int y) : Npc(SquirrelType, name, isAlive, x, y){
}

Squirrel::Squirrel(std::istream & is) : Npc(SquirrelType, is) {
}

bool Squirrel::accept(std::shared_ptr<Npc> visitor) {
    return visitor->fight(std::shared_ptr<Squirrel>(this, [](const Squirrel* p) {}));
}

bool Squirrel::fight(std::shared_ptr<Squirrel> other) {
    fightNotify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Bear> other) {
    fightNotify(other, false);
    return false;
}

bool Squirrel::fight(std::shared_ptr<Orc> other) {
    fightNotify(other, false);
    return false;
}

void Squirrel::print() {
    std::cout << "Squirrel(" <<  name_ << ", " <<  isAlive_ << ", " << x_ << ", " << y_ << ')' << std::endl;
}

void Squirrel::save(std::ostream &os) {
    os << SquirrelType << std::endl;
    Npc::save(os);
}
