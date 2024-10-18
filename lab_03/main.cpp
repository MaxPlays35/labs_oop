//
// Created by MaxPlays on 13/10/2024.
//

#include "src/array/Array.h"
#include "src/hexagon/Hexagon.h"
#include "src/octagon/Octagon.h"
#include "src/triangle/Triangle.h"

int main() {
    Shape::Array array{};
    std::string buffer{};

    int quantity = 0;
    std::cout << "Enter a quantity of figures:";
    std::cin >> quantity;

    for (int i = 0; i < quantity; ++i) {
        std::cout << "Enter a type for figure:";
        std::cin >> buffer;

        if (buffer == "triangle") {
            auto* triangle = new Shape::Triangle();
            std::cin >> *triangle;

            array.push_back(triangle);
        } else if (buffer == "hexagon") {
            auto* hexagon = new Shape::Hexagon();
            std::cin >> *hexagon;

            array.push_back(hexagon);
        } else if (buffer == "octagon") {
            auto* octagon = new Shape::Octagon();
            std::cin >> *octagon;

            array.push_back(octagon);
        } else {
            std::cout << "Bad type" << std::endl;
        }
    }

    std::cout << "Calculating square for figures" << std::endl;

    for (size_t i = 0 ; i < array.get_size(); ++i) {
        std::cout << *array[i] << '\n';
        std::cout << "Square: " << static_cast<double>(*array[i]) << std::endl;
    }

    std::cout << "Total square in array: " << array.get_total_area() << std::endl;

    size_t index;

    std::cout << "Enter an index to remove figure:";
    std::cin >> index;

    if (index >= array.get_size()) {
        std::cout << "You entered an bad index" << std::endl;
    } else {
        std::cout << "Removing a figure" << std::endl;
        array.remove_at(index);
    }

    std::cout << "Total square in array: " << array.get_total_area() << std::endl;

    for (size_t i = 0 ; i < array.get_size(); ++i) {
        delete array[i];
    }

    return 0;
}
