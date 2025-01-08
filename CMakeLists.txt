cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

project(lab7)

add_executable(
    run
    src/task2.cpp
    src/passenger.cpp
)