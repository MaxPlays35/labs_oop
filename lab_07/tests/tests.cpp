//
// Created by MaxPlays on 29/11/2024.
//

#include <gtest/gtest.h>

#include "../src/backuper/Backuper.h"
#include "../src/npc/Npc.h"
#include "../src/orc/Orc.h"
#include "../src/squirrel/Squirrel.h"
#include "../src/bear/Bear.h"

constexpr std::string inputFile = "input.txt";
constexpr std::string outputFile = "output.txt";

TEST(BACKUP, BACKUP_TEST) {
    std::shared_ptr<Npc> orc = std::make_shared<Orc>("Orc_1", true, 10, 10);
    std::shared_ptr<Npc> squirrel = std::make_shared<Squirrel>("Squirrel_1", true, 25, 25);
    std::shared_ptr<Npc> bear = std::make_shared<Bear>("Bear_1", true, 35, 35);

    squirrel->accept(bear);

    std::ofstream out(inputFile);
    auto backuper = Backuper(inputFile, outputFile);

    std::vector<std::shared_ptr<Npc>> npcies{orc, squirrel, bear};

    backuper.backup(npcies);

    auto backuper2 = Backuper(outputFile, inputFile);

    auto npciesLoaded = backuper2.loadNpcies();

    for (std::size_t i = 0; i < 3; ++i) {
        EXPECT_EQ(*npcies[i], *npciesLoaded[i]);
    }

    if (std::filesystem::exists(inputFile)) {
        std::filesystem::remove(inputFile);
    }

    if (std::filesystem::exists(outputFile)) {
        std::filesystem::remove(outputFile);
    }
}

TEST(ATTACKS, SQUIRREL_ATTACKS_ORC) {
    std::shared_ptr<Npc> orc = std::make_shared<Orc>("Orc_1", true, 10, 10);
    std::shared_ptr<Npc> squirrel = std::make_shared<Squirrel>("Squirrel_1", true, 25, 25);

    orc->accept(squirrel);

    EXPECT_TRUE(orc->isAlive());
    EXPECT_TRUE(squirrel->isAlive());
}

TEST(ATTACKS, SQUIRREL_ATTACKS_BEAR) {
    std::shared_ptr<Npc> squirrel = std::make_shared<Squirrel>("Squirrel_1", true, 25, 25);
    std::shared_ptr<Npc> bear = std::make_shared<Bear>("Bear_1", true, 35, 35);

    bear->accept(squirrel);

    EXPECT_TRUE(bear->isAlive());
    EXPECT_TRUE(squirrel->isAlive());
}

TEST(ATTACKS, SQUIRREL_ATTACKS_SQUIRREL) {
    std::shared_ptr<Npc> squirrel1 = std::make_shared<Squirrel>("Squirrel_1", true, 25, 25);
    std::shared_ptr<Npc> squirrel2 = std::make_shared<Squirrel>("Squirrel_2", true, 0, 0);

    squirrel2->accept(squirrel1);

    EXPECT_TRUE(squirrel1->isAlive());
    EXPECT_TRUE(squirrel2->isAlive());
}

TEST(ATTACKS, BEAR_ATTACKS_ORC) {
    std::shared_ptr<Npc> orc = std::make_shared<Orc>("Orc_1", true, 10, 10);
    std::shared_ptr<Npc> bear = std::make_shared<Bear>("Bear_1", true, 25, 25);

    orc->accept(bear);

    EXPECT_TRUE(bear->isAlive());
    EXPECT_TRUE(orc->isAlive());
}

TEST(ATTACKS, BEAR_ATTACKS_BEAR) {
    std::shared_ptr<Npc> bear1 = std::make_shared<Bear>("Bear_1", true, 25, 25);
    std::shared_ptr<Npc> bear2 = std::make_shared<Bear>("Bear_2", true, 35, 35);

    bear1->accept(bear2);

    EXPECT_TRUE(bear1->isAlive());
    EXPECT_TRUE(bear2->isAlive());
}

TEST(ATTACKS, BEAR_ATTACKS_SQUIRREL) {
    std::shared_ptr<Npc> bear = std::make_shared<Bear>("Bear_1", true, 25, 25);
    std::shared_ptr<Npc> squirrel = std::make_shared<Squirrel>("Squirrel", true, 0, 0);

    squirrel->accept(bear);

    EXPECT_TRUE(bear->isAlive());
    EXPECT_FALSE(squirrel->isAlive());
}

TEST(ATTACKS, ORC_ATTACKS_ORC) {
    std::shared_ptr<Npc> orc1 = std::make_shared<Orc>("Orc_1", true, 10, 10);
    std::shared_ptr<Npc> orc2 = std::make_shared<Orc>("Orc_2", true, 25, 25);

    orc1->accept(orc2);

    EXPECT_TRUE(orc2->isAlive());
    EXPECT_FALSE(orc1->isAlive());
}

TEST(ATTACKS, ORC_ATTACKS_BEAR) {
    std::shared_ptr<Npc> orc = std::make_shared<Orc>("Orc_1", true, 25, 25);
    std::shared_ptr<Npc> bear = std::make_shared<Bear>("Bear_1", true, 35, 35);

    bear->accept(orc);

    EXPECT_TRUE(orc->isAlive());
    EXPECT_FALSE(bear->isAlive());
}

TEST(ATTACKS, ORC_ATTACKS_SQUIRREL) {
    std::shared_ptr<Npc> orc = std::make_shared<Orc>("Orc_1", true, 25, 25);
    std::shared_ptr<Npc> squirrel = std::make_shared<Squirrel>("Squirrel", true, 0, 0);

    squirrel->accept(orc);

    EXPECT_TRUE(orc->isAlive());
    EXPECT_FALSE(squirrel->isAlive());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
