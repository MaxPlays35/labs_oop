cmake_minimum_required(VERSION 3.28)
project(lab_07)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME}_lib
            src/npc/Npc.h src/npc/Npc.cpp
            src/consts/consts.h src/consts/consts.cpp
            src/observer/IObserver.h src/observer/IObserver.cpp
            src/textObserver/TextObserver.h src/textObserver/TextObserver.cpp
            src/bear/Bear.h src/bear/Bear.cpp
            src/orc/Orc.h src/orc/Orc.cpp
            src/squirrel/Squirrel.h src/squirrel/Squirrel.cpp
            src/backuper/Backuper.h src/backuper/Backuper.cpp
            src/generator/Generator.h src/generator/Generator.cpp
            src/utils/Utils.h src/utils/Utils.cpp
            src/field/Field.h src/field/Field.cpp
            src/printer/Printer.h src/printer/Printer.cpp
            src/scopedThread/ScopedThread.h src/scopedThread/ScopedThread.cpp
            src/coroutine/Coroutine.h src/coroutine/Coroutine.cpp
            src/randomGenerator/RandomGenerator.h src/randomGenerator/RandomGenerator.cpp)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

add_executable(${PROJECT_NAME}_tests tests/tests.cpp)
target_link_libraries(${PROJECT_NAME}_tests ${PROJECT_NAME}_lib gtest_main)

add_test(NAME ${PROJECT_NAME}_tests COMMAND tests)
