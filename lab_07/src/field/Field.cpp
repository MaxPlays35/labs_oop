//
// Created by MaxPlays on 07/12/2024.
//

#include "Field.h"

#include <chrono>
#include <thread>

#include "../generator/Generator.h"
#include "../scopedThread/ScopedThread.h"
#include "../printer/Printer.h"

using namespace std::chrono_literals;

Field::Field(std::size_t sizeX, std::size_t sizeY) : sizeX_(sizeX), sizeY_(sizeY) {
    Generator generator;
    npcies_ = std::move(generator.generateNpcies(20, sizeX_, sizeY_));
}

std::vector<std::shared_ptr<Npc> > &Field::getNpcies() {
    return npcies_;
}

std::vector<std::vector<char> > Field::getField() const {
    std::vector field(sizeY_, std::vector<char>(sizeX_, ' '));

    for (const auto & npc: npcies_) {
        auto [x, y] = npc->position();

        if (!npc->isAlive()) {
            field[y][x] = 'x';
            continue;
        }

        switch (npc->getType()) {
            case SquirrelType:
                field[y][x] = 'S';
                break;
            case OrcType:
                field[y][x] = 'O';
                break;
            case BearType:
                field[y][x] = 'B';
                break;
            default:
                throw std::logic_error("Unknown type");
        }
    }

    return field;
}

Coroutine Field::move() {
    while (true) {
        for (auto & npc: npcies_) {
            if (!npc->isAlive()) {
                continue;
            }

            auto [x, y] = npc->position();
            int dx, dy;

            switch (npc->getType()) {
                case OrcType:
                    dx = generator_.generateInt(-20, 20);
                    dy = generator_.generateInt(std::abs(dx) - 20, 20 - std::abs(dx));
                    if (x + dx < sizeX_ and x + dx >= 0 and y + dy >= 0 and y + dy < sizeY_) {
                        npc->move(x + dx, y + dy);
                    }
                    break;
                case SquirrelType:
                    dx = generator_.generateInt(-5, 5);
                    dy = generator_.generateInt(std::abs(dx) - 5, 5 - std::abs(dx));
                    if (x + dx < sizeX_ and x + dx >= 0 and y + dy >= 0 and y + dy < sizeY_) {
                        npc->move(x + dx, y + dy);
                    }
                    break;
                case BearType:
                    dx = generator_.generateInt(-5, 5);
                    dy = generator_.generateInt(std::abs(dx) - 5, 5 - std::abs(dx));
                    if (x + dx < sizeX_ and x + dx >= 0 and y + dy >= 0 and y + dy < sizeY_) {
                        npc->move(x + dx, y + dy);
                    }
                    break;
                case BadType:
                    throw std::logic_error("Unknown type");
            }
        }

        co_await std::suspend_always{};
    }
}

Coroutine Field::fight() {
    while (true) {
        for (auto & attacker: npcies_) {
            for (auto & defender: npcies_) {
                if (attacker != defender and attacker->isAlive() and defender->isAlive() and attacker->
                    isClose(defender)) {
                    defender->accept(attacker);
                }
            }
        }

        co_await std::suspend_always{};
    }
}


void Field::start(std::size_t seconds) {
    auto start = std::chrono::steady_clock::now();
    auto duration_limit = std::chrono::seconds(seconds);

    auto st = ScopedThread([this, start, duration_limit] (){
        auto fightCor = fight();
        auto moveCor = move();

        while (std::chrono::steady_clock::now() - start < duration_limit){
            moveCor.resume();
            fightCor.resume();
            std::this_thread::sleep_for(500ms);
        }
    });

    while (std::chrono::steady_clock::now() - start < duration_limit){
        auto state = getField();
        std::stringstream stream;
        for (const auto & line : state) {
            for (const auto & ch : line) {
                stream << '[' << ch << ']';
            }
            stream << std::endl;
        }
        printer << stream.str();
        std::this_thread::sleep_for(1s);
    }
}

void Field::load(std::vector<std::shared_ptr<Npc>> npcies) {
    npcies_ = std::move(npcies);
}
