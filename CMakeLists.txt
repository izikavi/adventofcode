cmake_minimum_required(VERSION 3.25)
project(adventofcode)

set(CMAKE_CXX_STANDARD 14)

add_executable(aoc
    main.cpp
    Day1/day1-part1.cpp
    Day1/day1-part2.cpp
    Day2/day2-part1.cpp
    Day2/day2-part2.cpp
    Day3/day3-part1.cpp
    Day3/day3-part2.cpp
)
