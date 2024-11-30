//
// Created by MaxPlays on 29/11/2024.
//
#pragma once
#include <iostream>
#include <string>

constexpr std::string test("43242");

void print() {
    std::cout << test << std::endl;
}

enum NpcType {
    BadType,
    OrcType,
    SquirrelType,
    BearType
};