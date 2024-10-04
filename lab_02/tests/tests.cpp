//
// Created by Aleksandr Mikhailov on 21.09.2024.
//

#include <gtest/gtest.h>
#include "../src/task.h"

TEST(ADDITION_TESTS, TEST1) {
    auto first = decimal::Decimal{"100"};
    auto second = decimal::Decimal{"200"};
    auto result = first + second;
    ASSERT_EQ(result.to_string(), "300");
}

TEST(ADDITION_TESTS, TEST2) {
    auto first = decimal::Decimal{'2', '5', '3'};
    auto second = decimal::Decimal{"50"};
    auto result = first + second;
    ASSERT_EQ(result.to_string(), "303");
}

TEST(ADDITION_TESTS, TEST3) {
    auto first = decimal::Decimal{"1000"};
    auto second = decimal::Decimal{'1'};
    auto result = first + second;
    ASSERT_EQ(result.to_string(), "1001");
}

TEST(ADDITION_TESTS, TEST4) {
    auto first = decimal::Decimal{"0"};
    auto second = decimal::Decimal{"0"};
    auto result = first + second;
    ASSERT_EQ(result.to_string(), "0");
}

TEST(SUBSTRACTION_TESTS, TEST1) {
    auto first = decimal::Decimal{"2000"};
    auto second = decimal::Decimal{'1', '0', '2'};
    auto result = first - second;
    ASSERT_EQ(result.to_string(), "1898");
}

TEST(SUBSTRACTION_TESTS, TEST2) {
    auto first = decimal::Decimal{"100"};
    auto second = decimal::Decimal{"200"};
    EXPECT_THROW({
                 auto result = first - second;
                 }, std::out_of_range);
}

TEST(SUBSTRACTION_TESTS, TEST3) {
    auto first = decimal::Decimal{"1000"};
    auto second = decimal::Decimal{'1'};
    auto result = first - second;
    ASSERT_EQ(result.to_string(), "999");
}

TEST(EQUAL_TESTS, TEST1) {
    auto first = decimal::Decimal{"200"};
    auto second = decimal::Decimal{"5"};

    ASSERT_EQ(first == second, false);
}

TEST(EQUAL_TESTS, TEST2) {
    auto first = decimal::Decimal{"24"};
    auto second = decimal::Decimal{"24"};

    ASSERT_EQ(first == second, true);
}

TEST(EQUAL_TESTS, TEST3) {
    auto first = decimal::Decimal{"0"};
    auto second = decimal::Decimal{"0"};

    ASSERT_EQ(first == second, true);
}

TEST(NOT_EQUAL_TESTS, TEST1) {
    auto first = decimal::Decimal{"5"};
    auto second = decimal::Decimal{"3"};

    ASSERT_EQ(first != second, true);
}

TEST(NOT_EQUAL_TESTS, TEST2) {
    auto first = decimal::Decimal{"7"};
    auto second = decimal::Decimal{"7"};

    ASSERT_EQ(first != second, false);
}

TEST(NOT_EQUAL_TESTS, TEST3) {
    auto first = decimal::Decimal{"54"};
    auto second = decimal::Decimal{"26"};

    ASSERT_EQ(first != second, true);
}

TEST(LESS_TESTS, TEST1) {
    auto first = decimal::Decimal{"1"};
    auto second = decimal::Decimal{"2"};

    ASSERT_EQ(first < second, true);
}

TEST(LESS_TESTS, TEST2) {
    auto first = decimal::Decimal{"25"};
    auto second = decimal::Decimal{"4"};

    ASSERT_EQ(first < second, false);
}

TEST(LESS_TESTS, TEST3) {
    auto first = decimal::Decimal{"0"};
    auto second = decimal::Decimal{"0"};

    ASSERT_EQ(first < second, false);
}

TEST(GREATER_TESTS, TEST1) {
    auto first = decimal::Decimal{"3"};
    auto second = decimal::Decimal{"1"};

    ASSERT_EQ(first > second, true);
}

TEST(GREATER_TEST, TEST2) {
    auto first = decimal::Decimal{"10"};
    auto second = decimal::Decimal{"15"};

    ASSERT_EQ(first > second, false);
}

TEST(GREATER_TESTS, TEST3) {
    auto first = decimal::Decimal{"0"};
    auto second = decimal::Decimal{"0"};

    ASSERT_EQ(first > second, false);
}

TEST(SET_AND_ADD_TESTS, TEST1) {
    auto first = decimal::Decimal{"12"};
    auto second = decimal::Decimal{"5"};

    first += second;

    ASSERT_EQ(first.to_string(), "17");
}

TEST(SET_AND_ADD_TESTS, TEST2) {
    auto first = decimal::Decimal{"23"};
    auto second = decimal::Decimal{"7"};

    second += first;

    ASSERT_EQ(second.to_string(), "30");
}

TEST(SET_AND_SUB_TESTS, TEST1) {
    auto first = decimal::Decimal{"45"};
    auto second = decimal::Decimal{"20"};

    first -= second;

    ASSERT_EQ(first.to_string(), "25");
}

TEST(SET_AND_SUB_TESTS, TEST2) {
    auto first = decimal::Decimal{"7"};
    auto second = decimal::Decimal{"10"};

    EXPECT_THROW({
                    first -= second;
                 }, std::out_of_range);
}

TEST(WRONG_NUMBER_TESTS, TEST1) {
    EXPECT_THROW({
        auto first = decimal::Decimal{"0@#"};
    }, std::invalid_argument);
}

TEST(WRONG_NUMBER_TESTS, TEST2) {
    EXPECT_THROW({
        auto first = decimal::Decimal{"!987"};
    }, std::invalid_argument);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
