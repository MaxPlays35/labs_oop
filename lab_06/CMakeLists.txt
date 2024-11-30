cmake_minimum_required(VERSION 3.28)
project(lab_06)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}_lib
            src/npc/Npc.h src/npc/Npc.cpp
            src/consts/consts.h src/consts/consts.cpp
            src/observer/IObserver.h src/observer/IObserver.cpp
            src/textObserver/TextObserver.h src/textObserver/TextObserver.cpp)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

add_executable(${PROJECT_NAME}_tests tests/tests.cpp)
target_link_libraries(${PROJECT_NAME}_tests ${PROJECT_NAME}_lib gtest_main)

add_test(NAME ${PROJECT_NAME}_tests COMMAND tests)
