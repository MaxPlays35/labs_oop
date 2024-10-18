//
// Created by MaxPlays on 16/10/2024.
//

#include <gtest/gtest.h>

#include "../src/array/Array.h"
#include "../src/hexagon/Hexagon.h"
#include "../src/octagon/Octagon.h"
#include "../src/triangle/Triangle.h"

TEST(TRIANGLE_CONSTRUCTORS_TESTS, CENTER) {
    const auto center = Shape::Point{0.0, 0.0};
    const double length = 5.0;
    auto triangle = Shape::Triangle(center, length);

    const auto correct_points = std::vector<Shape::Point>{
        Shape::Point{
            center.x + std::cos(std::numbers::pi / 3.0) * length,
            center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
        },
        Shape::Point{
            center.x - std::cos(std::numbers::pi / 3.0) * length,
            center.y - (1.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
        },
        Shape::Point{
            center.x,
            center.y + (2.0 / 3.0) * std::sin(std::numbers::pi / 3.0) * length
        }
    };

    for (size_t i = 0; i < 3; ++i) {
        EXPECT_EQ(triangle[i], correct_points[i]);
    }
}

TEST(OCTAGON_CONSTRUCTORS_TESTS, CENTER) {
    const auto center = Shape::Point{1.0, 1.0 / std::tan(std::numbers::pi / 8.0)};
    const double length = 2.0;
    auto octagon = Shape::Octagon(center, length);

    const auto correct_points = std::vector<Shape::Point>{
        Shape::Point{center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
        Shape::Point{center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
        Shape::Point{center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
        Shape::Point{center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length},
        Shape::Point{center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length},
        Shape::Point{center.x - (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length},
        Shape::Point{center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y - 0.5 * length},
        Shape::Point{center.x + (1.0 / std::tan(std::numbers::pi / 8)) * 0.5 * length, center.y + 0.5 * length},
    };

    for (size_t i = 0; i < 8; ++i) {
        EXPECT_EQ(octagon[i], correct_points[i]);
    }
}

TEST(HEXAGON_CONSTRUCTORS_TESTS, CENTER) {
    const auto center = Shape::Point{1.0, 1.0 / std::tan(std::numbers::pi / 6.0)};
    const double length = 2.0;
    auto hexagon = Shape::Hexagon(center, length);

    const auto correct_points = std::vector<Shape::Point>{
        Shape::Point{center.x + 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
        Shape::Point{center.x - 0.5 * length, center.y - (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
        Shape::Point{center.x + 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
        Shape::Point{center.x - 0.5 * length, center.y + (1.0 / std::tan(std::numbers::pi / 6)) * 0.5 * length},
        Shape::Point{center.x + (1.0 / std::sin(std::numbers::pi / 6)) * 0.5 * length, center.y},
        Shape::Point{center.x - (1.0 / std::sin(std::numbers::pi / 6)) * 0.5 * length, center.y}
    };

    for (size_t i = 0; i < 6; ++i) {
        EXPECT_EQ(hexagon[i], correct_points[i]);
    }
}

TEST(TRIANGLE_SQUARE_TESTS, SQUARE) {
    const auto center = Shape::Point{0, 0};
    const double length = 5.0;
    auto triangle = Shape::Triangle(center, length);

    EXPECT_NEAR(length * length * std::sin(std::numbers::pi / 3.0) / 2, static_cast<double>(triangle), 1e-10);
}


TEST(OCTAGON_SQUARE_TESTS, SQUARE) {
    const auto center = Shape::Point{1.0, 1.0 / std::tan(std::numbers::pi / 8)};
    const double length = 2.0;
    auto octagon = Shape::Octagon(center, length);


    EXPECT_NEAR(2.0 * length * length * (std::numbers::sqrt2 + 1.0), static_cast<double>(octagon), 1e-10);
}

TEST(HEXAGON_SQUARE_TESTS, SQUARE) {
    const auto center = Shape::Point{1.0, 1.0 / std::tan(std::numbers::pi / 6.0)};
    const double length = 2.0;
    const auto hexagon = Shape::Hexagon(center, length);


    EXPECT_NEAR(3.0 * std::numbers::sqrt3 * length * length / 2.0, static_cast<double>(hexagon), 1e-10);
}

TEST(ARRAY_TESTS, TOTAL_SQUARE) {
    auto array = Shape::Array();

    auto figure1 = Shape::Triangle({0.0, 0.0}, 5.0);
    auto figure2 = Shape::Hexagon({1.0, 1.0 / std::tan(std::numbers::pi / 6.0)}, 2.0);
    auto figure3 = Shape::Octagon({1.0, 1.0 / std::tan(std::numbers::pi / 8.0)}, 2.0);

    double totalArea = static_cast<double>(figure1);

    array.push_back(&figure1);
    EXPECT_EQ(array.get_total_area(), totalArea);
    totalArea += static_cast<double>(figure2);

    array.push_back(&figure2);
    EXPECT_EQ(array.get_total_area(), totalArea);
    totalArea += static_cast<double>(figure3);

    array.push_back(&figure3);
    EXPECT_EQ(array.get_total_area(), totalArea);
}

TEST(ARRAY_TESTS, ADDING_TO_ARRAY) {
    auto array = Shape::Array();

    auto figure1 = Shape::Triangle({0.0, 0.0}, 5.0);
    auto figure2 = Shape::Hexagon({1.0, 1.0 / std::tan(std::numbers::pi / 6.0)}, 2.0);
    auto figure3 = Shape::Octagon({1.0, 1.0 / std::tan(std::numbers::pi / 8.0)}, 2.0);

    array.push_back(&figure1);
    EXPECT_EQ(array.get_size(), 1);

    array.push_back(&figure2);
    EXPECT_EQ(array.get_size(), 2);

    array.push_back(&figure3);
    EXPECT_EQ(array.get_size(), 3);
}

TEST(ARRAY_TESTS, REMOVING_FROM_ARRAY) {
    auto figure1 = Shape::Triangle({0.0, 0.0}, 5.0);
    auto figure2 = Shape::Hexagon({1.0, 1.0 / std::tan(std::numbers::pi / 6.0)}, 2.0);
    auto figure3 = Shape::Octagon({1.0, 1.0 / std::tan(std::numbers::pi / 8.0)}, 2.0);
    auto array = Shape::Array{
        &figure1, &figure2, &figure3
    };

    array.remove_at(1);

    EXPECT_EQ(array.get_size(), 2);
    EXPECT_EQ(array[0], &figure1);
    EXPECT_EQ(array[1], &figure3);
}

int main(int argc, char ** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
