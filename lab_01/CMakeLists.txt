cmake_minimum_required(VERSION 3.28)
project(lab_01)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${CMAKE_PROJECT_NAME}_lib src/task.cpp)
add_executable(${CMAKE_PROJECT_NAME} main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)

add_executable(tests tests/tests.cpp)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_lib gtest_main)

add_test(NAME ${CMAKE_PROJECT_NAME}_tests COMMAND tests)
