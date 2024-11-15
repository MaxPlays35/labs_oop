//
// Created by Aleksandr Mikhailov on 12.11.2024.
//
#pragma once

#include <memory>

#include "Node.h"
#include "../memoryResource/MemoryResource.h"
#include "../queueIterator/QueueIterator.h"

namespace PolymorphicQueue {
    template<class T, class allocator_type>
        requires std::is_default_constructible_v<T> and std::is_same_v<allocator_type, std::pmr::polymorphic_allocator<
                     T>>
    class Queue {
    private:
        using smart_ptr_node = std::shared_ptr<Node<T>>;
        using smart_ptr_value = std::unique_ptr<T, PolymorphicDeleter<T>>;

        std::shared_ptr<CustomMemoryResource> customResource;
        std::pmr::polymorphic_allocator<Node<T>> nodeAllocator_;

        smart_ptr_node first_;
        smart_ptr_node last_;
        size_t size_;
        allocator_type alloc_;

    public:
        explicit Queue(allocator_type allocator = {}) : customResource(new CustomMemoryResource()),
                                                        nodeAllocator_(customResource.get()), size_(0),
                                                        alloc_(allocator) {
            Node<T> * raw = nodeAllocator_.allocate(1);
            nodeAllocator_.construct(raw);

            first_ = smart_ptr_node(raw, [](auto pointer) {
            });
            last_ = smart_ptr_node(raw, [](auto pointer) {
            });
        }

        Queue(std::initializer_list<T> list, allocator_type allocator = {}) : Queue(allocator) {
            for (const auto & item: list) {
                push(item);
            }
        }

        Queue(const Queue & other): Queue(other.alloc_) {
            auto temp = other.first_;

            for (size_t i = 0; i < other.size_; ++i) {
                push(*temp->data);
                temp = temp->next;
            }
        }

        Queue(Queue && other) noexcept : customResource(std::move(other.customResource)),
                                         nodeAllocator_(std::move(other.nodeAllocator_)),
                                         first_(std::move(other.first_)),
                                         last_(std::move(other.last_)), size_(other.size_),
                                         alloc_(std::move(other.alloc_)) {
        }

        Queue &operator=(const Queue & other) {
            if (this != &other) {
                auto copy = Queue(other);
                this = std::move(copy);
            }

            return *this;
        }

        Queue &operator=(Queue && other) noexcept {
            if (this != &other) {
                this = std::move(other);
            }

            return *this;
        }

        bool empty() const {
            return size_ == 0;
        }

        size_t size() const {
            return size_;
        }

        void push(const T & value) {
            Node<T> * newNode = nodeAllocator_.allocate(1);
            nodeAllocator_.construct(newNode);

            T * newValue = alloc_.allocate(1);
            alloc_.construct(newValue);

            *newValue = value;

            last_->data = smart_ptr_value(newValue);

            last_->next = smart_ptr_node(newNode, [](auto pointer) {
            });
            last_ = last_->next;

            ++size_;
        }

        void pop() {
            if (size_ > 0) {
                auto temp = first_->next;

                std::allocator_traits<allocator_type>::destroy(alloc_, first_->data.get());
                alloc_.deallocate(first_->data.get(), 1);

                std::allocator_traits<decltype(nodeAllocator_)>::destroy(nodeAllocator_, first_.get());
                nodeAllocator_.deallocate(first_.get(), 1);

                first_ = temp;
                --size_;

                return;
            }

            throw std::logic_error("Empty queue");
        }

        T &front() {
            return *first_->data;
        }

        CustomIterator<T, Queue> begin() {
            return CustomIterator<T, Queue>(this, 0, this->size_, first_);
        }

        CustomIterator<T, Queue> end() {
            return CustomIterator<T, Queue>(this, this->size_, this->size_, last_);
        }

        ~Queue() {
            if (first_ != nullptr) {
                while (size_ > 0) {
                    auto temp = first_->next;

                    std::allocator_traits<allocator_type>::destroy(alloc_, first_->data.get());
                    alloc_.deallocate(first_->data.get(), 1);

                    std::allocator_traits<decltype(nodeAllocator_)>::destroy(nodeAllocator_, first_.get());
                    nodeAllocator_.deallocate(first_.get(), 1);

                    first_ = temp;
                    --size_;
                }

                std::allocator_traits<decltype(nodeAllocator_)>::destroy(nodeAllocator_, first_.get());
                nodeAllocator_.deallocate(first_.get(), 1);
            }
        }
    };
}
