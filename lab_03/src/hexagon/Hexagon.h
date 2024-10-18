//
// Created by MaxPlays on 16/10/2024.
//

#ifndef HEXAGON_H
#define HEXAGON_H
#include "../figure/Figure.h"

namespace Shape {
    class Hexagon : public Figure {
    public:
        Hexagon() = default;

        Hexagon(Point a, Point b, Point c, Point d, Point e, Point f);

        Hexagon(Point center, double length);

        Hexagon(const Hexagon & figure);

        Hexagon(Hexagon && figure) noexcept;

        Hexagon &operator=(const Hexagon & other) = default;

        Hexagon &operator=(Hexagon && other) noexcept;

        friend std::istream &operator>>(std::istream & is, Hexagon & figure);

        explicit operator double() const override;
    };
} // Shape

#endif //HEXAGON_H
