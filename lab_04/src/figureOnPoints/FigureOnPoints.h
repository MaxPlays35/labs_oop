//
// Created by MaxPlays on 23/11/2024.
//
#pragma once

#include <array>

#include "../figure/Figure.h"
#include "../point/Point.h"

namespace Shape {
    template<Numberic T, size_t H>
    class FigureOnPoints : public Figure<T>{
    protected:
        std::array<std::unique_ptr<Point<T>>, H> points;
    public:
        FigureOnPoints() = default;

        FigureOnPoints(std::initializer_list<Point<T> > pts) {
            size_t i = 0;
            for (const auto point: pts) {
                points[i] = std::make_unique<Point<T> >(point);
                ++i;
            }
        }

        FigureOnPoints(const FigureOnPoints & figure) {
            for (size_t i = 0; i < figure.points.size(); ++i) {
                points[i] = std::make_unique<Point<T> >(Point(figure.points[i]));
            }
        }

        FigureOnPoints(FigureOnPoints && figure) noexcept {
            points = std::move(figure.points);
        }

        FigureOnPoints &operator=(const FigureOnPoints & other) {
            auto copy = Figure(other);
            points = std::move(copy.points);

            return *this;
        };

        FigureOnPoints &operator=(FigureOnPoints && other) noexcept {
            points = std::move(other.points);

            return *this;
        }

        friend std::ostream &operator<<(std::ostream & os, const FigureOnPoints & figure) {
            switch (figure.points.size()) {
                case 3:
                    os << "Triangle(";
                break;
                case 6:
                    os << "Hexagon(";
                break;
                case 8:
                    os << "Octagon(";
                break;
                default:
                    os << "Shape(";
                break;
            }

            auto size = figure.points.size();

            for (size_t i = 0; i < size; ++i) {
                os << *figure.points[i];

                if (i != size - 1) {
                    os << ',';
                }
            }

            os << ')';

            return os;
        }

        friend std::istream &operator>>(std::istream & is, FigureOnPoints & figure) {
            int quantity;

            std::cout << "Enter a quantity of points for this shape: ";
            is >> quantity;

            auto points = std::array<Point<T>, H>(quantity);

            size_t i = 0;
            for (auto & point: points) {
                is >> point;
                figure.points[i] = std::make_unique<Point<T>>(point);
                ++i;
            }

            return is;
        }

        Point<T> operator[](size_t index) const {
            if (index >= points.size()) {
                throw std::out_of_range("Out of range! Check index");
            }

            return *points[index];
        }

        virtual bool operator==(const FigureOnPoints & other) const {
            if (points.size() != other.points.size()) {
                return false;
            }

            for (const auto & point: other.points) {
                if (std::ranges::find_if(points.begin(), points.end(), [&](const std::unique_ptr<Point<T>> & elem) { return *elem == *point; }) == points.
                    end()) {
                    return false;
                    }
            }

            return true;
        }

        virtual Point<T> get_center() override {
            if (points.empty()) {
                return {0, 0};
            }

            double x = 0;
            double y = 0;
            const auto count_of_points = static_cast<double>(points.size());

            for (const auto & point: points) {
                x += (*point).x;
                y += (*point).y;
            }

            return {x / count_of_points, y / count_of_points};
        }
    };
}