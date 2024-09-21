//
// Created by Aleksandr Mikhailov on 10.09.2024.
//

#include <gtest/gtest.h>
#include "../src/task.h"

TEST(TEST01, simple_test) {
    ASSERT_EQ(6, find_number(2, 7));
}

TEST(TEST02, simple_test) {
    ASSERT_EQ(50, find_number(10, 50));
}

TEST(TEST03, simple_test) {
    ASSERT_EQ(27, find_number(3, 28));
}

TEST(TEST04, broken_test) {
    ASSERT_EQ(-1, find_number(5, 4));
}

TEST(TEST05, bound_test) {
    ASSERT_EQ(1, find_number(1, 1));
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}