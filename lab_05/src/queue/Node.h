//
// Created by MaxPlays on 15/11/2024.
//
#pragma once
#include <type_traits>

namespace PolymorphicQueue {
    template<class T>
    struct PolymorphicDeleter {
        void operator()(T * ptr) const {
        }
    };

    template<class T>
        requires std::is_default_constructible_v<T>
    struct Node {
        std::unique_ptr<T, PolymorphicDeleter<T> > data;
        std::shared_ptr<Node> next;
    };
}
