//
// Created by MaxPlays on 16/10/2024.
//

#include "Hexagon.h"

namespace Shape {
    Hexagon::Hexagon(Point a, Point b, Point c, Point d, Point e, Point f) : Figure{a, b, c, d, e, f} {
    }

    Hexagon::Hexagon(Point center, double length) {
        points = std::vector<Point>{
            Point{center.x + 0.5 * length, center.y - (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
            Point{center.x - 0.5 * length, center.y - (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
            Point{center.x + 0.5 * length, center.y + (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
            Point{center.x - 0.5 * length, center.y + (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
            Point{center.x + (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length, center.y},
            Point{center.x - (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length, center.y}
        };
    }

    Hexagon::Hexagon(const Hexagon & figure) : Figure(figure){

    }

    Hexagon::Hexagon(Hexagon && figure) noexcept {
        points = std::move(figure.points);
    }

    Hexagon & Hexagon::operator=(Hexagon && other) noexcept {
        points = std::move(other.points);

        return *this;
    }

    std::istream & operator>>(std::istream & is, Hexagon & figure) {
        Point center;
        double length;

        std::cout << "Enter a length for side of Hexagon" << std::endl;
        is >> length;

        std::cout << "Enter a center for Hexagon" << std::endl;
        is >> center;

        figure.points = std::vector<Point>{
            Point{center.x + 0.5 * length, center.y - (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
            Point{center.x - 0.5 * length, center.y - (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
            Point{center.x + 0.5 * length, center.y + (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
            Point{center.x - 0.5 * length, center.y + (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
            Point{center.x + (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length, center.y},
            Point{center.x - (1 / std::tan(std::numbers::pi / 6)) * 0.5 * length, center.y}
        };

        return is;
    }
} // Shape
