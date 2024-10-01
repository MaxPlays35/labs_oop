//
// Created by Aleksandr Mikhailov on 21.09.2024.
//

#include <algorithm>
#include <iostream>

#include "src/task.h"

int main() {

    auto test = decimal::Decimal(std::string{"1000"});
    auto test2 = decimal::Decimal(std::string{"9"});

    auto test3 = test + test2;
    auto test4 = test - test2;

    return 0;
}
