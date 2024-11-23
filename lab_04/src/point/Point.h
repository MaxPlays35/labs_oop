//
// Created by MaxPlays on 13/10/2024.
//
#pragma once

#include <iostream>
#include <istream>
#include <cmath>
#include <memory>

namespace Shape {
    constexpr double kEps = 1e-10;

    template<class T>
    concept Numberic = std::is_scalar_v<T>;


    template <Numberic T>
    class Point {
    public:
        T x, y;

        Point(): x(0), y(0){}

        Point(T x, T y): x(x), y(y){}

        Point(const Point & other) = default;

        explicit Point(const std::unique_ptr<Point> & other) : Point(other->x, other->y) {}

        Point(Point && other) noexcept {
            x = std::move(other.x);
            y = std::move(other.y);
        }

        Point &operator=(const Point & other) = default;

        Point &operator=(Point && other) noexcept {
            x = std::move(other.x);
            y = std::move(other.y);

            return *this;
        }

        bool operator==(const Point & other) const {
            return std::fabs(x - other.x) < kEps  && std::fabs(y - other.y) < kEps;
        }

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

    template<Numberic T>
    double distance(const Point<T> & a, const Point<T> & b) {
        return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
}
