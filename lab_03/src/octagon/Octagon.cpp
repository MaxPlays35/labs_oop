//
// Created by MaxPlays on 15/10/2024.
//

#include "Octagon.h"

namespace Shape {
    Octagon::Octagon(Point a, Point b, Point c, Point d, Point e, Point f, Point g, Point h) : Figure{
        a, b, c, d, e, f, g, h
    } {
    }

    Octagon::Octagon(Point center, double length) {
        points = std::vector<Point>{
            Point{center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
            Point{center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
            Point{center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
            Point{center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
            Point{center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length},
            Point{center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length},
            Point{center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length},
            Point{center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length},
        };
    }

    Octagon::Octagon(const Octagon & figure) : Figure(figure) {
    }

    Octagon::Octagon(Octagon && figure) noexcept {
        points = std::move(figure.points);
    }

    Octagon &Octagon::operator=(Octagon && other) noexcept {
        points = std::move(other.points);

        return *this;
    }

    Octagon::operator double() const {
        const double length = distance(points[0], points[1]);

        return 2 * length * length * (std::numbers::sqrt2 + 1);
    }

    std::istream &operator>>(std::istream & is, Octagon & figure) {
        Point center;
        double length;

        std::cout << "Enter a length for side of Octagon" << std::endl;
        is >> length;

        std::cout << "Enter a center for Octagon" << std::endl;
        is >> center;

        figure.points = std::vector<Point>{
            Point{center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
            Point{center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
            Point{center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
            Point{center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
            Point{center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length},
            Point{center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length},
            Point{center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length},
            Point{center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length},
        };

        return is;
    }
}
