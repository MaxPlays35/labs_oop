//
// Created by Aleksandr Mikhailov on 01.12.2024.
//
#pragma once
#include <fstream>
#include <string>

#include "../npc/Npc.h"
#include "../orc/Orc.h"
#include "../squirrel/Squirrel.h"
#include "../bear/Bear.h"
#include "../textObserver/TextObserver.h"

class Npc;

class Backuper {
private:
    std::string inputFile_;
    std::string outputFile_;
    std::ifstream input_;
    std::ofstream output_;

    static std::shared_ptr<Npc> factory(std::istream & is) {
        int type;

        is >> type;

        switch (type) {
            case SquirrelType:
                return std::make_shared<Squirrel>(is);
            case OrcType:
                return std::make_shared<Orc>(is);
            case BearType:
                return std::make_shared<Bear>(is);;
            default:
                throw std::logic_error("Unknown type");
        }
    }

public:
    Backuper(std::string inputFile, std::string outputFile);

    void backup(std::vector<std::shared_ptr<Npc>> & npcies) {
        output_ << npcies.size() << std::endl;
        for (const auto & npc : npcies) {
            npc->save(output_);
        }
        output_.flush();
    }

    std::vector<std::shared_ptr<Npc>> loadNpcies() {
        std::size_t total = 0;
        std::vector<std::shared_ptr<Npc>> npcies;
        input_ >> total;

        for (std::size_t i = 0; i < total; ++i) {
            std::shared_ptr<Npc> npc = factory(input_);
            npc->subscribe(TextObserver::get());

            npcies.push_back(npc);
        }

        return npcies;
    }

    ~Backuper() = default;
};

