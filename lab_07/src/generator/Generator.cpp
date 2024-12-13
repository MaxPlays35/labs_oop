//
// Created by Aleksandr Mikhailov on 01.12.2024.
//

#include "Generator.h"

#include "../orc/Orc.h"
#include "../squirrel/Squirrel.h"
#include "../bear/Bear.h"

Generator::Generator() {
}

std::vector<std::shared_ptr<Npc>> Generator::generateNpcies(std::size_t size, std::size_t xMax, std::size_t yMax) {
    std::vector<std::shared_ptr<Npc>> npcies;

    for (std::size_t i = 0; i < size; ++i) {
        auto type = generator_.generateInt(1, 3);
        auto x = generator_.generateInt(0, xMax - 1);
        auto y = generator_.generateInt(0, yMax - 1);
        std::string name;

        switch (type) {
            case 1:
                name = std::string("Orc_") + std::to_string(i + 1);
                npcies.push_back(std::make_shared<Orc>(std::move(name), true, x, y));
                break;
            case 2:
                name = std::string("Squirrel_") + std::to_string(i + 1);
                npcies.push_back(std::make_shared<Squirrel>(std::move(name), true, x, y));
                break;
            case 3:
                name = std::string("Bear_") + std::to_string(i + 1);
                npcies.push_back(std::make_shared<Squirrel>(std::move(name), true, x, y));
                break;
        }
    }

    return npcies;
}
