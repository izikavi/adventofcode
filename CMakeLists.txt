cmake_minimum_required(VERSION 3.25)
project(adventofcode)

set(CMAKE_CXX_STANDARD 17)

# Utils library — no sources yet; change to STATIC and add .cpp files when utilities are extracted
add_library(utils_lib INTERFACE
        include/IReader.h)
target_include_directories(utils_lib INTERFACE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/utils
)

# Dynamically collect all day sources and their include dirs
set(all_day_sources ""
        utils/Reader.cpp
        utils/Reader.h
        SystemManager.cpp
        SystemManager.h)
set(all_day_include_dirs "")
file(GLOB day_dirs RELATIVE ${CMAKE_SOURCE_DIR}/days ${CMAKE_SOURCE_DIR}/days/day[0-9]*)
foreach(day_dir ${day_dirs})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/days/${day_dir})
        file(GLOB day_sources ${CMAKE_SOURCE_DIR}/days/${day_dir}/*.cpp)
        list(APPEND all_day_sources ${day_sources})
        list(APPEND all_day_include_dirs ${CMAKE_SOURCE_DIR}/days/${day_dir})
    endif()
endforeach()

# Single unified executable: ./aoc <day> [part]
add_executable(aoc main.cpp ${all_day_sources})
target_include_directories(aoc PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${all_day_include_dirs}
)
target_link_libraries(aoc PRIVATE utils_lib)
target_compile_options(aoc PRIVATE -Wall -Wextra -Wpedantic -Werror)
