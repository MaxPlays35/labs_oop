//
// Created by Aleksandr Mikhailov on 02.12.2024.
//
#pragma once
#include <vector>

std::vector<std::string> readFile(std::ifstream & in);

bool checkEqualsOfStrings(const std::vector<std::string> & current, const std::vector<std::string> & expected);
