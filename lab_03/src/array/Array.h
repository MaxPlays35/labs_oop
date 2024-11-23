//
// Created by MaxPlays on 16/10/2024.
//

#ifndef ARRAY_H
#define ARRAY_H
#include "../figure/Figure.h"

namespace Shape {
    class Array {
        Figure ** container = nullptr;
        double totalArea = 0;
        size_t size = 0, capacity = 0;

        explicit Array(size_t size);
    public:
        Array() = default;

        Array(std::initializer_list<Figure*> figures);

        Array(const Array & array);

        Array(Array && array) noexcept;

        Array& operator=(const Array & array);

        Array& operator=(Array && array) noexcept;

        void push_back(Figure* figure);

        void remove_at(size_t index);

        size_t get_size() const;

        size_t get_capacity() const;

        double get_total_area() const;

        Figure* operator[](size_t index) const;

        ~Array();
    };

    size_t calculate_capacity(size_t t);
} // Shape

#endif //ARRAY_H
