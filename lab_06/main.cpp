//
// Created by MaxPlays on 29/11/2024.
//

#include "src/backuper/Backuper.h"
#include "src/bear/Bear.h"
#include "src/generator/Generator.h"
#include "src/npc/Npc.h"
#include "src/squirrel/Squirrel.h"
#include "src/textObserver/TextObserver.h"

int main() {
    auto gen = Generator();

    auto val = gen.generateNpcies(100);

    auto bk = Backuper("test1.txt", "test2.txt");

    bk.backup(val);

    auto bk2 = Backuper("test2.txt", "test1.txt");

    auto npcies = bk2.loadNpcies();

    for (std::size_t i = 20; i <= 100; i += 20) {
        std::cout << "-----------" << i << "meters" << "-----------" << std::endl;
        for (auto & attacker : npcies) {
            for (auto & defender : npcies) {
                if (attacker != defender and attacker->isAlive() and defender->isAlive() and attacker->isClose(defender, i)) {
                    defender->accept(attacker);
                }
            }
        }
    }



    return 0;
}
