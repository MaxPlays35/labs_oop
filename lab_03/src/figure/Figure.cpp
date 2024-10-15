//
// Created by MaxPlays on 13/10/2024.
//

#include <algorithm>

#include "Figure.h"

namespace Shape {
    Figure::Figure(std::initializer_list<Point> pts) {
        for (const auto point : pts) {
            points.emplace_back(point);
        }
    }

    Figure::Figure(const Figure & figure) {
        points = figure.points;
    }

    Figure::Figure(Figure && figure) noexcept {
        points = std::move(figure.points);
    }

    Figure & Figure::operator=(Figure && other) noexcept {
        points = std::move(other.points);
        return *this;
    }

    bool Figure::operator==(const Figure & other) const {
        if (points.size() != other.points.size()) {
            return false;
        }

        for (const auto & point : other.points) {
            if (std::ranges::find(points, point) == points.end()) {
                return false;
            }
        }

        return true;
    }

    Point Figure::get_center() {
        if (points.empty()) {
            return {0, 0};
        }

        double x = 0;
        double y = 0;
        const auto count_of_points = static_cast<double>(points.size());

        for (const auto & point : points) {
            x += point.x;
            y += point.y;
        }

        return {x / count_of_points, y / count_of_points};
    }

    std::ostream & operator<<(std::ostream & os, const Figure & figure) {
        os << "Shape(";
        for (auto & point : figure.points) {
            os << point << ',';
        }
        os << ')';

        return os;
    }

    std::istream & operator>>(std::istream & is, Figure & figure) {
        int quantity;

        std::cout << "Enter a quantity of points for this shape: ";
        is >> quantity;

        figure.points = std::vector<Point>(quantity);

        for (auto & point : figure.points) {
            is >> point;
        }

        return is;
    }
}
