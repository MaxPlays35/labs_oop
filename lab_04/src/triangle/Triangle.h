//
// Created by MaxPlays on 14/10/2024.
//
#pragma once

#include "../consts/Consts.h"
#include "../figureOnPoints/FigureOnPoints.h"


namespace Shape {
    template<Numberic T>
    class Triangle : public FigureOnPoints<T, kTrianglePoints> {
    public:
        Triangle() = default;

        Triangle(Point<T> a, Point<T> b, Point<T> c) : FigureOnPoints<T, kTrianglePoints>({a, b, c}) {
        }

        Triangle(Point<T> center, double length) {
            FigureOnPoints<T, kTrianglePoints>::points[0] =
                    std::make_unique<Point<T> >(Point<double>{
                        center.x + std::cos(std::numbers::pi / 3.0) * length,
                        center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
                    });
            FigureOnPoints<T, kTrianglePoints>::points[1] =
                    std::make_unique<Point<T> >(Point<double>{
                        center.x - std::cos(std::numbers::pi / 3.0) * length,
                        center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
                    });
            FigureOnPoints<T, kTrianglePoints>::points[2] =
                    std::make_unique<Point<T> >(Point<double>{
                        center.x,
                        center.y + (2.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
                    });
        }

        Triangle(const Triangle & figure) : FigureOnPoints<T, kTrianglePoints>(figure) {
        }

        Triangle(Triangle && figure) noexcept {
            FigureOnPoints<T, kHexagonPoints>::points = std::move(figure);
        }

        Triangle &operator=(const Triangle & other) {
            auto copy = Triangle(other);
            FigureOnPoints<T, kTrianglePoints>::points = std::move(copy.points);

            return *this;
        }

        Triangle &operator=(Triangle && other) noexcept {
            FigureOnPoints<T, kTrianglePoints>::points = std::move(other.points);

            return *this;
        }

        friend std::istream &operator>>(std::istream & is, Triangle & figure) {
            Point<T> center;
            T length;

            std::cout << "Enter a length for side of Triangle:";
            is >> length;

            std::cout << "Enter a center for Triangle:";
            is >> center;

            figure.points[0] = std::make_unique<Point<T> >(Point{
                center.x + std::cos(std::numbers::pi / 3.0) * length,
                center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
            });
            figure.points[1] = std::make_unique<Point<T> >(Point{
                center.x - std::cos(std::numbers::pi / 3.0) * length,
                center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
            });
            figure.points[2] = std::make_unique<Point<T> >(Point{
                center.x,
                center.y + (2.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
            });

            return is;
        }

        explicit operator double() const override {
            const double length = distance(*FigureOnPoints<T, kTrianglePoints>::points[0],
                                           *FigureOnPoints<T, kTrianglePoints>::points[1]);

            return std::numbers::sqrt3 * length * length / 4;
        }
    };
}
