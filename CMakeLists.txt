cmake_minimum_required(VERSION 3.25)
project(adventofcode)

set(CMAKE_CXX_STANDARD 17)

add_library(utils_lib INTERFACE
        include/IReader.h
        include/IFactory.h)
target_include_directories(utils_lib INTERFACE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/utils
)

set(all_day_sources ""
        src/utils/Reader.cpp
        src/SystemManager.cpp
        src/utils/Factory.cpp
        src/days/ISolver/ISolver.cpp
)

set(all_day_include_dirs "")
set(code_src "${CMAKE_SOURCE_DIR}/src")

file(GLOB day_dirs RELATIVE ${code_src}/days ${code_src}/days/day[0-9]*)
foreach(day_dir ${day_dirs})
    if(IS_DIRECTORY ${code_src}/days/${day_dir})
        file(GLOB day_sources ${code_src}/days/${day_dir}/*.cpp)
        list(APPEND all_day_sources ${day_sources})
        list(APPEND all_day_include_dirs ${code_src}/days/${day_dir})
    endif()
endforeach()

message(STATUS "files: ${all_day_sources}")

add_executable(aoc main.cpp ${all_day_sources})
target_include_directories(aoc PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${all_day_include_dirs}
)

target_link_libraries(aoc PRIVATE utils_lib)
target_compile_definitions(aoc PRIVATE EXTRA_DEBUG)
#target_compile_options(aoc PRIVATE -Wall -Wextra -Wpedantic -Werror)
