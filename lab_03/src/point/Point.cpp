//
// Created by MaxPlays on 15/10/2024.
//

#include "Point.h"

namespace Shape {
    bool Point::operator==(const Point & other) const {
        return std::fabs(x - other.x) < kEps  && std::fabs(y - other.y) < kEps;
    }

    double distance(const Point & a, const Point & b) {
        return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }
}
