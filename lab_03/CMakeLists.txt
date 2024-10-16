cmake_minimum_required(VERSION 3.28)
project(lab_03)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}_lib src/figure/Figure.h src/figure/Figure.cpp src/point/Point.h src/point/Point.cpp src/triangle/Triangle.h src/triangle/Triangle.cpp src/octagon/Octagon.h src/octagon/Octagon.cpp src/hexagon/Hexagon.h src/hexagon/Hexagon.cpp)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

#add_executable(${PROJECT_NAME}_tests tests/tests.cpp)
#target_link_libraries(${PROJECT_NAME}_tests ${PROJECT_NAME}_lib gtest_main)

#add_test(NAME ${PROJECT_NAME}_tests COMMAND tests)
