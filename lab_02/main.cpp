//
// Created by Aleksandr Mikhailov on 21.09.2024.
//

#include <algorithm>
#include <iostream>

#include "src/task.h"

int main() {

    auto test = decimal::Decimal(std::string{"55555"});
    auto test2 = decimal::Decimal(std::string{"55555"});

    test + test2;

    return 0;
}
