//
// Created by MaxPlays on 29/11/2024.
//

#include "TextObserver.h"

#include <iostream>
#include <sstream>

#include "../printer/Printer.h"

std::shared_ptr<IObserver> TextObserver::get() {
    static TextObserver instance;

    return std::shared_ptr<IObserver>(&instance, [](IObserver* observer) {});
}

void TextObserver::onFight(std::shared_ptr<Npc> attacker, std::shared_ptr<Npc> defender, bool win) {
    if (win) {
        std::stringstream stream;
        stream << "Somebody killed" << std::endl;
        stream << "Attacker:" << std::endl;
        attacker->print(stream);
        stream << "Defender:" << std::endl;
        defender->print(stream);
        printer << stream.str();
    }
}

