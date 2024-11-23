//
// Created by MaxPlays on 16/10/2024.
//
#pragma once

#include "../consts/Consts.h"
#include "../figureOnPoints/FigureOnPoints.h"

namespace Shape {
    template<Numberic T>
    class Hexagon : public FigureOnPoints<T, kHexagonPoints> {
    public:
        Hexagon() = default;

        Hexagon(Point<T> a, Point<T> b, Point<T> c, Point<T> d, Point<T> e, Point<T> f): FigureOnPoints<T,
            kHexagonPoints>{a, b, c, d, e, f} {
        }

        Hexagon(Point<T> center, double length) {
            FigureOnPoints<T, kHexagonPoints>::points[0] =
                    std::make_unique<Point<T> >(
                        Point{center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                    );
            FigureOnPoints<T, kHexagonPoints>::points[1] =
                    std::make_unique<Point<T> >(
                        Point{center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}

                    );
            FigureOnPoints<T, kHexagonPoints>::points[2] =
                    std::make_unique<Point<T> >(
                        Point{center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                    );
            FigureOnPoints<T, kHexagonPoints>::points[3] =
                    std::make_unique<Point<T> >(
                        Point{center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                    );
            FigureOnPoints<T, kHexagonPoints>::points[4] =
                    std::make_unique<Point<T> >(
                        Point{center.x + (1.0 / std::sin(std::numbers::pi / 6)) * 0.5 * length, center.y}

                    );
            FigureOnPoints<T, kHexagonPoints>::points[5] =
                    std::make_unique<Point<T> >(
                        Point{center.x - (1.0 / std::sin(std::numbers::pi / 6)) * 0.5 * length, center.y}
                    );
        }

        Hexagon(const Hexagon & figure) : FigureOnPoints<T, kHexagonPoints>(figure) {
        }

        Hexagon(Hexagon && figure) noexcept {
            auto copy = Hexagon(figure);
            FigureOnPoints<T, kHexagonPoints>::points = std::move(copy.points);
        }

        Hexagon &operator=(const Hexagon & other) {
            auto copy = Hexagon(other);
            FigureOnPoints<T, kHexagonPoints>::points = std::move(copy.points);

            return *this;
        }

        Hexagon &operator=(Hexagon && other) noexcept {
            FigureOnPoints<T, kHexagonPoints>::points = std::move(other.points);

            return *this;
        }

        friend std::istream &operator>>(std::istream & is, Hexagon & figure) {
            Point<T> center;
            double length;

            std::cout << "Enter a length for side of Hexagon" << std::endl;
            is >> length;

            std::cout << "Enter a center for Hexagon" << std::endl;
            is >> center;

            figure.points[0] =
                    std::make_unique<Point<T> >(
                        Point{center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                    );
            figure.points[1] =
                    std::make_unique<Point<T> >(
                        Point{center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}

                    );
            figure.points[2] =
                    std::make_unique<Point<T> >(
                        Point{center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                    );
            figure.points[3] =
                    std::make_unique<Point<T> >(
                        Point{center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length}
                    );
            figure.points[4] =
                    std::make_unique<Point<T> >(
                        Point{center.x + (1.0 / std::sin(std::numbers::pi / 6)) * 0.5 * length, center.y}

                    );
            figure.points[5] =
                    std::make_unique<Point<T> >(
                        Point{center.x - (1.0 / std::sin(std::numbers::pi / 6)) * 0.5 * length, center.y}
                    );

            return is;
        }

        explicit operator double() const override {
            const double length = distance(*FigureOnPoints<T, kHexagonPoints>::points[0],
                                           *FigureOnPoints<T, kHexagonPoints>::points[1]);

            return 3 * std::numbers::sqrt3 * length * length / 2;
        }
    };
} // Shape
