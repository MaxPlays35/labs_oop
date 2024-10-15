//
// Created by MaxPlays on 14/10/2024.
//

#include "Triangle.h"

namespace Shape {
    Triangle::Triangle(Point a, Point b, Point c) : Figure{a, b, c} {
    }

    Triangle::Triangle(Point center, double length) {
        points = std::vector<Point>{
            Point{
                center.x + std::cos(std::numbers::pi / 3.0),
                center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
            },
            Point{
                center.x - std::cos(std::numbers::pi / 3.0),
                center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
            },
            Point{
                center.x,
                center.y + (2.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
            }
        };
    }

    Triangle::Triangle(const Triangle & figure) : Figure(figure) {

    }

    Triangle::Triangle(Triangle && figure) noexcept {
        points = std::move(figure.points);
    }

    Triangle & Triangle::operator=(Triangle && other) noexcept {
        points = std::move(other.points);

        return *this;
    }

    Triangle::operator double() const {
        return std::sqrt(3) * distance(points[0], points[1]) / 4;
    }

    std::ostream & operator<<(std::ostream & os, const Triangle & figure) {
        os << "Triangle(";
        for (size_t i = 0; i < 3; ++i) {
            os << figure.points[i];

            if (i != 2) {
                os << ',';
            }
        }
        os << ')';

        return os;
    }

    std::istream & operator>>(std::istream & is, Triangle & figure) {
        Point center;
        double length;

        std::cout << "Enter a length for side of Triangle" << std::endl;
        is >> length;

        std::cout << "Enter a center for Triangle" << std::endl;
        is >> center;

        figure.points = std::vector<Point>{
            Point{
                center.x + std::cos(std::numbers::pi / 3.0),
                center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
            },
            Point{
                center.x - std::cos(std::numbers::pi / 3.0),
                center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
            },
            Point{
                center.x,
                center.y + (2.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
            }
        };

        return is;
    }
}
