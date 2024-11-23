//
// Created by MaxPlays on 13/10/2024.
//
#pragma once

#include <iostream>
#include <istream>
#include <memory>
#include <vector>
#include "../point/Point.h"

namespace Shape {
    template<Numberic T>
    class Figure {

    public:
        // Figure() = default;
        //
        // Figure(std::initializer_list<Point<T> > pts) {
        //     for (const auto point: pts) {
        //         points.emplace_back(std::make_unique<Point<T> >(point));
        //     }
        // }
        //
        // Figure(const Figure & figure) {
        //     for (const auto & point: figure.points) {
        //         points.emplace_back(std::make_unique<Point<T> >(Point(point)));
        //     }
        // }
        //
        // Figure(Figure && figure) noexcept {
        //     points = std::move(figure.points);
        // }

        // Figure &operator=(const Figure & other) {
        //     auto copy = Figure(other);
        //     points = std::move(copy.points);
        //
        //     return *this;
        // };
        //
        // Figure &operator=(Figure && other) noexcept {
        //     points = std::move(other.points);
        //
        //     return *this;
        // }

        // friend std::ostream &operator<<(std::ostream & os, const Figure & figure) {
        //     switch (figure.points.size()) {
        //         case 3:
        //             os << "Triangle(";
        //             break;
        //         case 6:
        //             os << "Hexagon(";
        //             break;
        //         case 8:
        //             os << "Octagon(";
        //             break;
        //         default:
        //             os << "Shape(";
        //             break;
        //     }
        //
        //     auto size = figure.points.size();
        //
        //     for (size_t i = 0; i < size; ++i) {
        //         os << *figure.points[i];
        //
        //         if (i != size - 1) {
        //             os << ',';
        //         }
        //     }
        //
        //     os << ')';
        //
        //     return os;
        // }
        //
        // friend std::istream &operator>>(std::istream & is, Figure & figure) {
        //     int quantity;
        //
        //     std::cout << "Enter a quantity of points for this shape: ";
        //     is >> quantity;
        //
        //     auto points = std::vector<Point<T> >(quantity);
        //
        //     for (auto & point: points) {
        //         is >> point;
        //         figure.points.emplace_back(std::make_unique<Point<T> >(point));
        //     }
        //
        //     return is;
        // }

        // Point<T> operator[](size_t index) const {
        //     if (index >= points.size()) {
        //         throw std::out_of_range("Out of range! Check index");
        //     }
        //
        //     return *points[index];
        // }
        //
        // virtual bool operator==(const Figure & other) const {
        //     if (points.size() != other.points.size()) {
        //         return false;
        //     }
        //
        //     for (const auto & point: other.points) {
        //         if (std::ranges::find_if(points.begin(), points.end(), [&](const std::unique_ptr<Point<T>> & elem) { return *elem == *point; }) == points.
        //             end()) {
        //             return false;
        //         }
        //     }
        //
        //     return true;
        // }

        virtual Point<T> get_center() = 0;

        virtual explicit operator double() const = 0;

        virtual ~Figure() = default;
    };
}

