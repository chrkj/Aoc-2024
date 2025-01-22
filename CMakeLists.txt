cmake_minimum_required(VERSION 3.30)
project(Aoc_2024)

set(CMAKE_CXX_STANDARD 26)

add_executable(
        Aoc_2024 src/main.cpp
        src/Solutions/Day1.h
        src/Solutions/Day2.h
        src/Solutions/Day3.h
        src/Solutions/Day4.h
        src/Solutions/Day5.h
        src/Solutions/Day6.h
        src/Solutions/Day7.h
        src/Utils/Utils.h
)
