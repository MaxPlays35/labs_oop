//
// Created by MaxPlays on 13/10/2024.
//

#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <istream>
#include <cmath>

namespace Shape {
    const double kEps = 1e-10;

    class Point {
    public:
        double x, y;

        bool operator==(const Point & other) const;

        friend std::istream &operator>>(std::istream & is, Point & point) {
            std::cout << "Enter x and y of the point(separated by space):";
            is >> point.x >> point.y;
            return is;
        }

        friend std::ostream &operator<<(std::ostream & os, const Point & point) {
            os << "Point(" << point.x << ", " << point.y << ')';

            return os;
        }
    };

    double distance(const Point & a, const Point & b);
}

#endif //POINT_H
