//
// Created by Aleksandr Mikhailov on 11.11.2024.
//

#include <iostream>
#include <queue>
#include <vector>

#include "src/memoryResource/MemoryResource.h"
#include "src/queue/Queue.h"

int main() {
    PolymorphicQueue::CustomMemoryResource customResource;
    std::pmr::polymorphic_allocator<int> allocatorInt(&customResource);
    std::pmr::polymorphic_allocator<std::pair<int, int> > allocatorPair(&customResource);

    PolymorphicQueue::Queue<int, std::pmr::polymorphic_allocator<int> > queue1(allocatorInt);

    for (int i = 0; i < 10; i++) {
        queue1.push(i);
    }

    for (const auto & test: queue1) {
        std::cout << "Queue1: " << test << std::endl;
    }

    PolymorphicQueue::Queue<std::pair<int, int>, std::pmr::polymorphic_allocator<std::pair<int, int>>>
            queue2(allocatorPair);

    for (int i = 0; i < 10; i++) {
        queue2.push(std::make_pair(i, i + 10));
    }

    for (const auto & [fst, snd]: queue2) {
        std::cout << "Queue2: " << fst << ' ' << snd << std::endl;
    }

    return 0;
}
