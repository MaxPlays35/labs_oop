//
// Created by MaxPlays on 13/12/2024.
//

#include "Printer.h"

Printer::Printer(std::ostream & os) : os_(os) {
}

Printer & Printer::operator<<(std::ostream &(* fun)(std::ostream &)) {
    std::shared_lock lock(printMutex);
    os_ << std::endl;
    return *this;
}
