//
// Created by Aleksandr Mikhailov on 10.09.2024.
//

#include "task.h"

int find_number(const unsigned int divider, const unsigned int bound) {
    const unsigned int number = (bound / divider) * divider;

    if (number > 0 && number <= bound) {
        return number;
    }

    return -1;
}
