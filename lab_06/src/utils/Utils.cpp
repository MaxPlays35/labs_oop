//
// Created by Aleksandr Mikhailov on 02.12.2024.
//
#include <fstream>

#include "Utils.h"

std::vector<std::string> readFile(std::ifstream & in) {
    std::vector<std::string> result;
    std::string buffer;

    while (std::getline(in, buffer)) {
        result.push_back(buffer);
    }

    return result;
}

bool checkEqualsOfStrings(const std::vector<std::string> & current, const std::vector<std::string> & expected) {
    if (current.size() != expected.size()) {
        return false;
    }

    for (int i = 0; i < current.size(); i++) {
        if (current[i] != expected[i]) {
            return false;
        }
    }

    return true;
}