//
// Created by MaxPlays on 16/10/2024.
//

#include "Array.h"

namespace Shape {
    Array::Array(size_t size) : size(size), capacity(size) {
        container = static_cast<Figure **>(std::malloc(sizeof(Figure *) * size));
    }

    Array::Array(const std::initializer_list<Figure *> figures): Array(figures.size()) {
        size_t i = 0;
        for (const auto figure: figures) {
            container[i] = figure;
            ++i;
        }
    }

    Array::Array(const Array & array) : Array(array.get_size()) {
        for (size_t i = 0; i < array.size; ++i) {
            container[i] = array[i];
        }
    }

    Array::Array(Array && array) noexcept : container(array.container), size(array.size), capacity(array.capacity) {
        array.container = nullptr;
    }

    Array &Array::operator=(const Array & array) {
        auto copy = Array(array);

        container = copy.container;
        size = copy.size;
        capacity = copy.capacity;
        totalArea = copy.totalArea;

        copy.container = nullptr;

        return *this;
    }

    Array &Array::operator=(Array && array) noexcept {
        container = array.container;
        size = array.size;
        capacity = array.capacity;
        totalArea = array.totalArea;

        array.container = nullptr;

        return *this;
    }

    void Array::push_back(Figure * figure) {
        if (size == 0) {
            container = static_cast<Figure **>(std::malloc(sizeof(Figure*)));
            capacity = 1;
        }

        if (size == capacity) {
            capacity = calculate_capacity(size + 1);
            container = static_cast<Figure **>(std::realloc(container, sizeof(Figure*) * capacity));
        }

        container[size] = figure;
        ++size;

        totalArea += static_cast<double>(*figure);
    }

    void Array::remove_at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Out of range! Check index");
        }

        totalArea -= static_cast<double>(*container[index]);

        for (size_t i = index; i < size; ++i) {
            container[i] = container[i + 1];
        }
        --size;
    }

    size_t Array::get_size() const {
        return size;
    }

    size_t Array::get_capacity() const {
        return capacity;
    }

    double Array::get_total_area() const {
        return totalArea;
    }

    Figure * Array::operator[](size_t index) const {
        return container[index];
    }

    Array::~Array() {
        delete container;
    }

    size_t calculate_capacity(size_t size) {
        return static_cast<size_t>(std::ceil(std::numbers::phi * size));
    }
} // Shape
