//
// Created by Aleksandr Mikhailov on 12.11.2024.
//

#pragma once

#include <map>
#include <memory_resource>
#include <stdexcept>

namespace PolymorphicQueue {
    class Block {
    private:
        size_t offset_;
        size_t size_;
    public:

        Block() = default;

        Block(const size_t offset, const size_t size) : offset_(offset), size_(size) {}

        bool operator==(const Block & other) const {
            return offset_ == other.offset_ && size_ == other.size_;
        }

        size_t getSize() const {
            return size_;
        }

        size_t getOffset() const {
            return offset_;
        }

        ~Block() = default;
    };

    class CustomMemoryResource : public std::pmr::memory_resource {
        static constexpr size_t max_size = 1024;
        char buffer[max_size];
        std::map<size_t, Block> used_blocks;
    public:
        void* do_allocate(size_t bytes, size_t alignment) override {
            size_t prevOffset = 0;

            for (const auto& [key, block] : used_blocks) {
                if (key - prevOffset >= bytes) {
                    break;
                }

                prevOffset = key + block.getSize();
            }

            if (prevOffset + bytes >= max_size) {
                throw std::bad_alloc();
            }

            used_blocks.emplace(prevOffset, Block(prevOffset, bytes));
            return buffer + prevOffset;
        }

        void do_deallocate(void* ptr, size_t bytes, size_t alignment) override {
            for(const auto& [key, _] : used_blocks) {
                if (ptr == buffer + key) {
                    used_blocks.erase(key);
                    return;
                }
            }

            throw std::logic_error("Trying to free a block that doesn't exist");
        }

        bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override {
            return this == &other;
        }

        std::map<size_t, Block> get_used_blocks() {
            return used_blocks;
        }
    };
}

