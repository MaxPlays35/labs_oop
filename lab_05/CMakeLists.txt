cmake_minimum_required(VERSION 3.28)
project(lab_05)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}_lib src/memoryResource/MemoryResource.h src/memoryResource/MemoryResource.cpp src/queue/Queue.h src/queue/Queue.cpp src/queueIterator/QueueIterator.h src/queueIterator/QueueIterator.cpp src/queue/Node.h)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

add_executable(${PROJECT_NAME}_tests tests/tests.cpp)
target_link_libraries(${PROJECT_NAME}_tests ${PROJECT_NAME}_lib gtest_main)

add_test(NAME ${PROJECT_NAME}_tests COMMAND tests)
