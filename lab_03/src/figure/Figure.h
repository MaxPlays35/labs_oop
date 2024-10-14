//
// Created by MaxPlays on 13/10/2024.
//

#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
#include <istream>
#include <vector>
#include "../point/Point.h"

namespace Shape {
    class Figure {
    protected:
        std::vector<Point> points;

    public:
        Figure() = default;

        Figure(std::initializer_list<Point> pts);

        Figure(const Figure & figure);

        Figure(Figure && figure) noexcept;

        Figure &operator=(const Figure & other) = default;

        Figure &operator=(Figure && other) noexcept;

        friend std::ostream &operator<<(std::ostream & os, const Figure & figure);

        friend std::istream &operator>>(std::istream & is, Figure & figure);

        virtual bool operator==(const Figure & other) const;

        virtual Point get_center();

        virtual explicit operator double() const = 0;

        virtual ~Figure() = default;
    };
}


#endif //FIGURE_H
