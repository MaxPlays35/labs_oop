//
// Created by MaxPlays on 29/11/2024.
//

#include "TextObserver.h"

#include <iostream>

std::shared_ptr<IObserver> TextObserver::get() {
    static TextObserver instance;

    return std::shared_ptr<IObserver>(&instance, [](IObserver* observer) {});
}

void TextObserver::onFight(std::shared_ptr<Npc> attacker, std::shared_ptr<Npc> defender, bool win) {
    if (win) {
        std::cout << "Somebody killed" << std::endl;
        std::cout << "Attacker:" << std::endl;
        attacker->print();
        std::cout << "Defender:" << std::endl;
        defender->print();
    }
}

