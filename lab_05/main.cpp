//
// Created by Aleksandr Mikhailov on 11.11.2024.
//

#include <queue>
#include <vector>

#include "src/memoryResource/MemoryResource.h"
#include "src/queue/Queue.h"

int main() {
    CustomMemoryResource customResource;
    std::pmr::polymorphic_allocator<int> allocator(&customResource);

    std::pmr::vector<int> vector(allocator);

    for (int i = 0; i < 100; i++) {
        vector.push_back(i);
    }

    Queue<int, std::pmr::polymorphic_allocator<int>> queue(allocator);

    for (int i = 0; i < 2; i++) {
        queue.push(i);
    }

    Queue<int, std::pmr::polymorphic_allocator<int>> queue2(queue);

    auto test = std::move(queue2);

    return 0;
}
