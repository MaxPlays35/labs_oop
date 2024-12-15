//
// Created by MaxPlays on 29/11/2024.
//

#include <iostream>

#include "src/backuper/Backuper.h"
#include "src/bear/Bear.h"
#include "src/field/Field.h"
#include "src/generator/Generator.h"
#include "src/npc/Npc.h"
#include "src/squirrel/Squirrel.h"
#include "src/textObserver/TextObserver.h"

int main() {
    auto gen = Generator();

    auto val = gen.generateNpcies(100, 50, 50);

    auto bk = Backuper("test1.txt", "test2.txt");

    bk.backup(val);

    auto bk2 = Backuper("test2.txt", "test1.txt");

    auto npcies = bk2.loadNpcies();

    Field field(50, 50);
    field.load(npcies);

    field.start(15);


    return 0;
}
