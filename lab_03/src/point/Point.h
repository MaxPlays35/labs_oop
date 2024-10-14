//
// Created by MaxPlays on 13/10/2024.
//

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <istream>

namespace Shape {
    class Point {
    public:
        double x, y;

        bool operator==(const Point & other) const {
            return x == other.x && y == other.y;
        }

        friend std::istream &operator>>(std::istream & is, Point & point) {
            std::cout << "Enter x and y of the point: ";
            is >> point.x >> point.y;
            return is;
        }

        friend std::ostream &operator<<(std::ostream & os, const Point & point) {
            os << "Point(" << point.x << ", " << point.y << ')';

            return os;
        }
    };
}

#endif //POINT_H
