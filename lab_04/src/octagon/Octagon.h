//
// Created by MaxPlays on 15/10/2024.
//
#pragma once

#include "../consts/Consts.h"
#include "../figureOnPoints/FigureOnPoints.h"


namespace Shape {
    template<Numberic T>
    class Octagon : public FigureOnPoints<T, kOctagonPoints> {
    public:
        Octagon() = default;

        Octagon(Point<T> a, Point<T> b, Point<T> c, Point<T> d, Point<T> e, Point<T> f, Point<T> g,
                Point<T> h) : FigureOnPoints<T, kOctagonPoints>{a, b, c, e, f, g, h} {
        }

        Octagon(Point<T> center, double length) {
            FigureOnPoints<T, kOctagonPoints>::points[0] =
                    std::make_unique<Point<T> >(Point{
                        center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                    });
            FigureOnPoints<T, kOctagonPoints>::points[1] =
                    std::make_unique<Point<T> >(Point{
                        center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                    });
            FigureOnPoints<T, kOctagonPoints>::points[2] =
                    std::make_unique<Point<T> >(Point{
                        center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                    });
            FigureOnPoints<T, kOctagonPoints>::points[3] =
                    std::make_unique<Point<T> >(Point{
                        center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                    });
            FigureOnPoints<T, kOctagonPoints>::points[4] =
                    std::make_unique<Point<T> >(Point{
                        center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length
                    });
            FigureOnPoints<T, kOctagonPoints>::points[5] =
                    std::make_unique<Point<T> >(Point{
                        center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length
                    });
            FigureOnPoints<T, kOctagonPoints>::points[6] =
                    std::make_unique<Point<T> >(Point{
                        center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length
                    });
            FigureOnPoints<T, kOctagonPoints>::points[7] =
                    std::make_unique<Point<T> >(Point{
                        center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length
                    });
        }

        Octagon(const Octagon & figure) : FigureOnPoints<T, kOctagonPoints>(figure) {
        }

        Octagon(Octagon && figure) noexcept {
            auto copy = Octagon(figure);
            FigureOnPoints<T, kHexagonPoints>::points = std::move(copy.points);
        }

        Octagon &operator=(const Octagon & other) {
            auto copy = Octagon(other);
            FigureOnPoints<T, kOctagonPoints>::points = std::move(copy.points);

            return *this;
        }

        Octagon &operator=(Octagon && other) noexcept {
            FigureOnPoints<T, kOctagonPoints>::points = std::move(other.points);

            return *this;
        }

        friend std::istream &operator>>(std::istream & is, Octagon & figure) {
            Point<T> center;
            T length;

            std::cout << "Enter a length for side of Octagon" << std::endl;
            is >> length;

            std::cout << "Enter a center for Octagon" << std::endl;
            is >> center;

            figure.points[0] =
                    std::make_unique<Point<T> >(Point{
                        center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                    });
            figure.points[1] =
                    std::make_unique<Point<T> >(Point{
                        center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                    });
            figure.points[2] =
                    std::make_unique<Point<T> >(Point{
                        center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                    });
            figure.points[3] =
                    std::make_unique<Point<T> >(Point{
                        center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length
                    });
            figure.points[4] =
                    std::make_unique<Point<T> >(Point{
                        center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length
                    });
            figure.points[5] =
                    std::make_unique<Point<T> >(Point{
                        center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length
                    });
            figure.points[6] =
                    std::make_unique<Point<T> >(Point{
                        center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length
                    });
            figure.points[7] =
                    std::make_unique<Point<T> >(Point{
                        center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length
                    });

            return is;
        }

        explicit operator double() const override {
            const double length = distance(*FigureOnPoints<T, kOctagonPoints>::points[0],
                                           *FigureOnPoints<T, kOctagonPoints>::points[1]);

            return 2 * length * length * (std::numbers::sqrt2 + 1);
        }
    };
};
