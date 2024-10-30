//
// Created by MaxPlays on 16/10/2024.
//
#pragma once


#include "../figure/Figure.h"

namespace Shape {
    inline size_t calculate_capacity(size_t size) {
        return static_cast<size_t>(std::ceil(std::numbers::phi * size));
    }

    template<class T, class U>
    concept FigureOrPtrToFigure = std::derived_from<std::remove_pointer_t<T>, Figure<U>> and Numberic<U>;

    template<class T, class U>
        requires(FigureOrPtrToFigure<T, U>)
    class Array {
        std::unique_ptr<T[]> container = nullptr;
        double totalArea = 0;
        size_t size = 0, capacity = 0;

        explicit Array(size_t size) : size(size), capacity(size) {
            container = std::make_unique<T[]>(size);
        }

    public:
        Array() = default;

        Array(std::initializer_list<T> figures) requires(!std::is_pointer_v<T>): Array(figures.size()) {
            size_t i = 0;
            for (const auto figure: figures) {
                container[i] = figure;
                totalArea += static_cast<double>(figure);
                ++i;
            }
        }

        Array(std::initializer_list<T> figures) requires(std::is_pointer_v<T>): Array(figures.size()) {
            size_t i = 0;
            for (const auto figure: figures) {
                container[i] = std::move(figure);
                totalArea += static_cast<double>(*figure);
                ++i;
            }
        }

        Array(const Array & array) : totalArea(array.totalArea), size(array.size), capacity(array.capacity) {
            for (size_t i = 0; i < size; ++i) {
                container[i] = array.container[i];
            }
        }


        Array(Array && array) noexcept {
            container = std::move(array.container);
        }

        Array &operator=(const Array & array) {
            auto copy = Array(array);
            container = std::move(copy.container);

            return *this;
        }

        Array &operator=(Array && array) noexcept {
            container = std::move(array.container);

            return *this;
        }

        void push_back(T figure) requires(!std::is_pointer_v<T>) {
            if (size == 0) {
                container = std::make_unique<T[]>(1);
                capacity = 1;
            }

            if (size == capacity) {
                capacity = calculate_capacity(size + 1);

                auto buffer = std::make_unique<T[]>(capacity);
                for (size_t i = 0; i < size; ++i) {
                    buffer[i] = std::move(container[i]);
                }

                container = std::move(buffer);
            }

            container[size] = figure;
            ++size;

            totalArea += static_cast<double>(figure);
        }

        void push_back(T figure) requires(std::is_pointer_v<T>) {
            if (size == 0) {
                container = std::make_unique<T[]>(1);
                capacity = 1;
            }

            if (size == capacity) {
                capacity = calculate_capacity(size + 1);

                auto buffer = std::make_unique<T[]>(capacity);
                for (size_t i = 0; i < size; ++i) {
                    buffer[i] = container[i];
                }

                container = std::move(buffer);
            }

            container[size] = figure;
            ++size;

            totalArea += static_cast<double>(*figure);
        }

        void remove_at(size_t index) requires(!std::is_pointer_v<T>)
        {
            if (index >= size) {
                throw std::out_of_range("Out of range! Check index");
            }

            totalArea -= static_cast<double>(container[index]);

            for (size_t i = index; i < size; ++i) {
                container[i] = std::move(container[i + 1]);
            }
            --size;
        }

        void remove_at(size_t index) requires(std::is_pointer_v<T>)
        {
            if (index >= size) {
                throw std::out_of_range("Out of range! Check index");
            }

            totalArea -= static_cast<double>(*container[index]);

            for (size_t i = index; i < size; ++i) {
                container[i] = container[i + 1];
            }
            --size;
        }

        size_t get_size() const {
            return size;
        }

        size_t get_capacity() const {
            return capacity;
        }

        double get_total_area() const {
            return totalArea;
        }

        T operator[](size_t index) const {
            return container[index];
        }

        ~Array() = default;
    };
} // Shape
