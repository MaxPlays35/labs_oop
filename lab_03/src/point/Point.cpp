//
// Created by MaxPlays on 15/10/2024.
//

#include "Point.h"

namespace Shape {
    bool Point::operator==(const Point & other) const {
        return x == other.x && y == other.y;
    }

    double distance(const Point & a, const Point & b) {
        return std::sqrt((a.x - b.x) * (a.x - b.x) - (a.y - b.y) * (a.y - b.y));
    }
}
