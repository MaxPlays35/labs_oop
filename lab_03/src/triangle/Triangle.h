//
// Created by MaxPlays on 14/10/2024.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "../figure/Figure.h"


namespace Shape {
    class Triangle : public Figure {
        Triangle() = default;

        Triangle(Point a, Point b, Point c);

        Triangle(Point center, double length);

        Triangle(const Triangle & figure);

        Triangle(Triangle && figure) noexcept;

        Triangle &operator=(const Triangle & other) = default;

        Triangle &operator=(Triangle && other) noexcept;

        friend std::ostream &operator<<(std::ostream & os, const Triangle & figure);

        friend std::istream &operator>>(std::istream & is, Triangle & figure);

        explicit operator double() const override;
    };
}



#endif //TRIANGLE_H
