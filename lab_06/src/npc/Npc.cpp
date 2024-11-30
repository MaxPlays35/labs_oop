//
// Created by MaxPlays on 29/11/2024.
//

#include "Npc.h"

#include <utility>

Npc::Npc(NpcType type, std::string name, bool isAlive, int x, int y) : type_(type), name_(std::move(name)),
                                                                       isAlive_(isAlive), x_(x), y_(y) {
}

Npc::Npc(const Npc & other) : type_(other.type_), name_(other.name_), isAlive_(other.isAlive_), x_(other.x_),
                              y_(other.y_) {
}
