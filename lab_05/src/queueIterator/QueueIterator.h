//
// Created by MaxPlays on 15/11/2024.
//

#pragma once
#include <iterator>
#include <memory>

#include "../queue/Node.h"

namespace PolymorphicQueue {
    template<class ItemT, class QueueT>
    class CustomIterator {
        QueueT * queue_;
        size_t index_;
        size_t size_;
        std::shared_ptr<Node<ItemT> > current_element_;

    public:
        using difference_type = int;
        using value_type = ItemT;
        using reference = ItemT &;
        using pointer = ItemT *;
        using iterator_category = std::forward_iterator_tag;

        CustomIterator(QueueT * queue, size_t index, size_t size,
                       std::shared_ptr<Node<ItemT>> element) : queue_(queue),
                                                                index_(index), size_(size), current_element_(element) {
        }

        ItemT operator*() {
            if (index_ >= size_) throw std::out_of_range("Iterator is beyond the bounds of the container");
            return *current_element_->data;
        }

        ItemT operator->() {
            if (index_ >= size_) throw std::out_of_range("Iterator is beyond the bounds of the container");
            return *current_element_->data;
        }

        CustomIterator operator++() {
            if (index_ < size_) {
                current_element_ = current_element_->next;
                ++index_;
            }

            return *this;
        }

        bool operator!=(const CustomIterator<ItemT, QueueT> & other) const {
            return this->index_ != other.index_ || this->current_element_ != other.current_element_;
        }
    };
}
