//
// Created by MaxPlays on 28/10/2024.
//

#include "src/triangle/Triangle.h"

int main() {
    Shape::Point<double> center{0, 0};
    double length = 5;

    // auto test = Shape::Triangle<double>{
    //     Shape::Point{
    //         center.x + std::cos(std::numbers::pi / 3.0) * length,
    //         center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
    //     },
    //     Shape::Point{
    //         center.x - std::cos(std::numbers::pi / 3.0) * length,
    //         center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
    //     },
    //     Shape::Point{
    //         center.x,
    //         center.y + (2.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
    //     }
    // };

    auto test2 = Shape::Triangle<double>(center, 5.0);

    std::cout << double(test2) << std::endl;

    return 0;
}
