//
// Created by MaxPlays on 15/10/2024.
//
#pragma once

#include "../figure/Figure.h"


namespace Shape {
    template<Numberic T>
    class Octagon : public Figure<T> {
    public:
        Octagon() = default;

        Octagon(Point<T> a, Point<T> b, Point<T> c, Point<T> d, Point<T> e, Point<T> f, Point<T> g,
                Point<T> h) : Figure<T>{a, b, c, e, f, g, h} {
        }

        Octagon(Point<T> center, double length) {
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                })
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                })
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                })
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                })
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length
                })
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length
                })
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length
                })
            );
            Figure<T>::points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length
                })
            );
        }

        Octagon(const Octagon & figure) : Figure<T>(figure) {
        }

        Octagon(Octagon && figure) noexcept {
            auto copy = Octagon(figure);
            figure.points = std::move(copy.points);
        }

        Octagon &operator=(const Octagon & other) {
            auto copy = Octagon(other);
            Figure<T>::points = std::move(copy.points);

            return *this;
        }

        Octagon &operator=(Octagon && other) noexcept {
            Figure<T>::points = std::move(other.points);

            return *this;
        }

        friend std::istream &operator>>(std::istream & is, Octagon & figure) {
            Point<T> center;
            T length;

            std::cout << "Enter a length for side of Octagon" << std::endl;
            is >> length;

            std::cout << "Enter a center for Octagon" << std::endl;
            is >> center;

            figure.points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                })
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                })
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                })
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                })
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length
                })
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length
                })
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length
                })
            );
            figure.points.emplace_back(
                std::make_unique<Point<T> >(Point{
                    center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length
                })
            );

            return is;
        }

        explicit operator double() const override {
            const double length = distance(*Figure<T>::points[0], *Figure<T>::points[1]);

            return 2 * length * length * (std::numbers::sqrt2 + 1);
        }
    };
};
