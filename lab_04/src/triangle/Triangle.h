//
// Created by MaxPlays on 14/10/2024.
//
#pragma once

#include "../figure/Figure.h"


namespace Shape {
    template <Numberic T>
    class Triangle : public Figure<T> {
    public:
        Triangle() = default;

        Triangle(Point<T> a, Point<T> b, Point<T> c) : Figure<T>{a, b, c} {}

        Triangle(Point<T> center, double length) {
            Figure<T>::points = std::vector<Point<double>>{
                Point{
                    center.x + std::cos(std::numbers::pi / 3.0) * length,
                    center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
                },
                Point{
                    center.x - std::cos(std::numbers::pi / 3.0) * length,
                    center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
                },
                Point{
                    center.x,
                    center.y + (2.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
                }
            };
        }

        Triangle(const Triangle & figure) : Figure<T>(figure){}

        Triangle(Triangle && figure) noexcept {
            Figure<T>::points = std::move(figure);
        }

        Triangle &operator=(const Triangle & other) {
            auto copy = Triangle(other);
            Figure<T>::points = std::move(copy.points);

            return *this;
        }

        Triangle &operator=(Triangle && other) noexcept {
            Figure<T>::points = std::move(other.points);

            return *this;
        }

        // friend std::istream &operator>>(std::istream & is, Triangle & figure) {
        //     Point<T> center;
        //     double length;
        //
        //     std::cout << "Enter a length for side of Triangle:";
        //     is >> length;
        //
        //     std::cout << "Enter a center for Triangle:";
        //     is >> center;
        //
        //     figure.points = std::vector<Point<double>>{
        //         Point{
        //             center.x + std::cos(std::numbers::pi / 3.0) * length,
        //             center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
        //         },
        //         Point{
        //             center.x - std::cos(std::numbers::pi / 3.0) * length,
        //             center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
        //         },
        //         Point{
        //             center.x,
        //             center.y + (2.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
        //         }
        //     };
        //
        //     return is;
        // }

        explicit operator double() const override {
            const double length = distance(*Figure<T>::points[0], *Figure<T>::points[1]);

            return std::numbers::sqrt3 * length * length / 4;
        }
    };
}
