//
// Created by MaxPlays on 16/10/2024.
//
#pragma once

#include "../figure/Figure.h"

namespace Shape {
    template<Numberic T>
    class Hexagon : public Figure<T> {
    public:
        Hexagon() = default;

        Hexagon(Point<T> a, Point<T> b, Point<T> c, Point<T> d, Point<T> e, Point<T> f): Figure<T>{a, b, c, d, e, f} {
        }

        Hexagon(Point<T> center, double length) {
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                )
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}

                )
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                )
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                )
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x + (1.0 / std::sin(std::numbers::pi / 6)) * 0.5 * length, center.y}

                )
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x - (1.0 / std::sin(std::numbers::pi / 6)) * 0.5 * length, center.y}
                )
            );
        }

        Hexagon(const Hexagon & figure) : Figure<T>(figure) {
        }

        Hexagon(Hexagon && figure) noexcept {
            auto copy = Hexagon(figure);
            Figure<T>::points = std::move(copy.points);
        }

        Hexagon &operator=(const Hexagon & other) {
            auto copy = Hexagon(other);
            Figure<T>::points = std::move(copy.points);

            return *this;
        }

        Hexagon &operator=(Hexagon && other) noexcept {
            Figure<T>::points = std::move(other.points);

            return *this;
        }

        friend std::istream &operator>>(std::istream & is, Hexagon & figure) {
            Point<T> center;
            double length;

            std::cout << "Enter a length for side of Hexagon" << std::endl;
            is >> length;

            std::cout << "Enter a center for Hexagon" << std::endl;
            is >> center;

            figure.points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                )
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}

                )
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                )
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                )
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x + (1.0 / std::sin(std::numbers::pi / 6)) * 0.5 * length, center.y}

                )
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(
                    Point{center.x - (1.0 / std::sin(std::numbers::pi / 6)) * 0.5 * length, center.y}
                )
            );

            return is;
        }

        explicit operator double() const override {
            const double length = distance(*Figure<T>::points[0], *Figure<T>::points[1]);

            return 3 * std::numbers::sqrt3 * length * length / 2;
        }
    };
} // Shape
