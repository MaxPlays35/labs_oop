//
// Created by MaxPlays on 15/10/2024.
//

#ifndef OCTAGON_H
#define OCTAGON_H
#include "../figure/Figure.h"


namespace Shape {
    class Octagon : public Figure {
        Octagon() = default;

        Octagon(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h);

        Octagon(Point center, double length);

        Octagon(const Octagon & figure);

        Octagon(Octagon && figure) noexcept;

        Octagon &operator=(const Octagon & other) = default;

        Octagon &operator=(Octagon && other) noexcept;

        friend std::ostream &operator<<(std::ostream & os, const Octagon & figure);

        friend std::istream &operator>>(std::istream & is, Octagon & figure);

        explicit operator double() const override;
    };
};




#endif //OCTAGON_H
