//
// Created by Aleksandr Mikhailov on 12.11.2024.
//
#pragma once

#include "../memoryResource/MemoryResource.h"

template<class T>
struct PolymorphicDeleter {
    void operator()(T *ptr) const {
    }
};

template<class T, class allocator_type>
    requires std::is_default_constructible_v<T> and std::is_same_v<allocator_type, std::pmr::polymorphic_allocator<T> >
class Queue {
private:
    struct Node {
        std::unique_ptr<T, PolymorphicDeleter<T>> data;
        std::unique_ptr<Node, PolymorphicDeleter<Node> > next;
    };

    using smart_ptr_node = std::unique_ptr<Node, PolymorphicDeleter<Node>>;
    using smart_ptr_value = std::unique_ptr<T, PolymorphicDeleter<T>>;

    CustomMemoryResource customResource;
    std::pmr::polymorphic_allocator<Node> nodeAllocator_;

    smart_ptr_node first_;
    smart_ptr_node last_;
    size_t size_;
    allocator_type alloc_;

public:
    explicit Queue(allocator_type allocator = {}) : nodeAllocator_(
                                                        std::pmr::polymorphic_allocator<Node>(&customResource)),
                                                    size_(0), alloc_(allocator) {
        Node *raw = nodeAllocator_.allocate(sizeof(Node));

        first_ = smart_ptr_node(raw);
        last_ = smart_ptr_node(raw);
    }

    Queue(std::initializer_list<T> list, allocator_type allocator = {}) : Queue(allocator) {
        for (const auto &item: list) {
            push(item);
        }
    }

    Queue(const Queue &other): Queue(other.alloc_) {
        auto temp = smart_ptr_node(other.first_.get());

        while (temp->next != nullptr) {
            push(*temp->data);

            temp = smart_ptr_node(temp->next.get());
        }
    }

    Queue(Queue &&other) noexcept : customResource(std::move(other.customResource)), nodeAllocator_(std::move(other.nodeAllocator_)), first_(std::move(other.first_)),
                                    last_(std::move(other.last_)), size_(other.size_), alloc_(other.alloc_) {}

    Queue& operator=(const Queue &other) {
        if (this != &other) {
            auto copy = Queue(other);
            this = std::move(copy);
        }

        return *this;
    }

    Queue& operator=(Queue&& other) noexcept {
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

    void push(const T &value) {
        Node *newNode = nodeAllocator_.allocate(sizeof(Node));
        T* newValue = alloc_.allocate(sizeof(T));
        *newValue = value;

        last_->data = smart_ptr_value(newValue);

        last_->next = smart_ptr_node(newNode);
        last_ = smart_ptr_node(last_->next.get());

        ++size_;
    }

    void pop() {
        if (size_ > 0) {
            auto temp = smart_ptr(first_->next.get());

            if constexpr (std::is_default_constructible_v<T>) {
                std::allocator_traits<allocator_type>::destroy(alloc_, first_->data);
            }

            std::allocator_traits<allocator_type>::destroy(nodeAllocator_, first_);

            alloc_.deallocate(first_->data.get(), sizeof(T));
            nodeAllocator_.deallocate(first_.get(), sizeof(Node));

            first_ = std::move(temp);
            --size_;
        }
    }

    T &front() {
        return *first_->data;
    }

    ~Queue() {
        if (first_ != nullptr) {
            auto temp = smart_ptr_node(first_.get());

            while (temp->next != nullptr) {
                temp = smart_ptr_node(temp->next.get());
            }
        }
    }
};
