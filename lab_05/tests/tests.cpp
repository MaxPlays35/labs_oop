//
// Created by Aleksandr Mikhailov on 12.11.2024.
//

#include <gtest/gtest.h>

#include "../src/queue/Queue.h"


template<class T>
bool cmp(PolymorphicQueue::Queue<T, std::pmr::polymorphic_allocator<T>> queue, std::vector<T> correct){
    if (queue.size() != correct.size()) {
        return false;
    }

    auto i = 0;
    for (auto item : queue){
        if (item != correct[i]) {
            return false;
        }

        ++i;
    }

    return true;
}

TEST(PolymorphicQueueTests, ShouldCreatePolymorphicQueueCorrectly){
    PolymorphicQueue::CustomMemoryResource customResource;
    std::pmr::polymorphic_allocator<int> allocator(&customResource);

    auto queue = PolymorphicQueue::Queue({1, 2, 3, 4, 5}, allocator);
    auto correct = std::array{1, 2, 3, 4, 5};

    for(size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(queue.front(), correct[i]);
        queue.pop();
    }
}

TEST(PolymorphicQueueTests, ShouldCreatePolymorphicQueueCorrectlyWithPush){
    PolymorphicQueue::CustomMemoryResource customResource;
    std::pmr::polymorphic_allocator<int> allocator(&customResource);

    auto queue = PolymorphicQueue::Queue<int, std::pmr::polymorphic_allocator<int>>(allocator);

    queue.push(1);
    queue.push(2);
    queue.push(3);

    auto correct = std::vector{1, 2, 3};

    EXPECT_TRUE(cmp(queue, correct));
}

TEST(PolymorphicQueueTests, ShouldPopItemCorrectly){
    PolymorphicQueue::CustomMemoryResource customResource;
    std::pmr::polymorphic_allocator<int> allocator(&customResource);

    auto queue = PolymorphicQueue::Queue({1,2,3}, allocator);
    auto correct = std::vector{2, 3};

    queue.pop();

    EXPECT_TRUE(cmp(queue, correct));
}

TEST(PolymorphicQueueTests, ShouldCreatePolymorphicQueueCorrectlyWithComplicatedType){
    PolymorphicQueue::CustomMemoryResource customResource;
    std::pmr::polymorphic_allocator<std::pair<int, int>> allocator(&customResource);

    auto queue = PolymorphicQueue::Queue<std::pair<int, int>, std::pmr::polymorphic_allocator<std::pair<int, int>>>(allocator);

    queue.push(std::make_pair(1, 2));
    queue.push(std::make_pair(3, 4));
    queue.push(std::make_pair(5, 6));

    auto correct = std::vector<std::pair<int, int>>({
        {1, 2},
        {3, 4},
        {5, 6}
    });

    EXPECT_TRUE(cmp(queue, correct));
}

TEST(PolymorphicQueueTests, ShouldCreateUsedBlocksCorrectly){
    PolymorphicQueue::CustomMemoryResource customResource;
    std::pmr::polymorphic_allocator<int> allocator(&customResource);

    auto queue = PolymorphicQueue::Queue<int, std::pmr::polymorphic_allocator<int>>({1}, allocator);

    auto blocks = customResource.get_used_blocks();


    EXPECT_EQ(blocks.size(), 1);
    EXPECT_EQ(blocks[0], PolymorphicQueue::Block(0, 4));

    queue.push(2);
    queue.push(3);

    blocks = customResource.get_used_blocks();

    EXPECT_EQ(blocks.size(), 3);
    EXPECT_EQ(blocks[4], PolymorphicQueue::Block(4, 4));
    EXPECT_EQ(blocks[8], PolymorphicQueue::Block(8, 4));

}

TEST(PolymorphicQueueTests, IteratorsShouldWorkCorrectly){
    PolymorphicQueue::CustomMemoryResource customResource;
    std::pmr::polymorphic_allocator<int> allocator(&customResource);

    auto queue = PolymorphicQueue::Queue<int, std::pmr::polymorphic_allocator<int>>({1, 2, 3}, allocator);
    auto correct = std::vector<int>{1, 2, 3};

    auto i = 0;
    for (auto item : queue){
        EXPECT_EQ(item, correct[i]);
        ++i;
    }

}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
