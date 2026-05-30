#include "day3.h"
#include "SolverRegistry.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

namespace {

std::vector<std::string> read_lines(const std::string& path) {
    std::ifstream f(path);
    std::vector<std::string> lines;
    for (std::string line; std::getline(f, line);)
        lines.push_back(line);
    return lines;
}

void solve_part1(const std::string& input_path) {
    auto data = read_lines(input_path);
    // TODO: implement
    (void)data;
}

void solve_part2(const std::string& input_path) {
    auto data = read_lines(input_path);
    // TODO: implement
    (void)data;
}

} // namespace

void Day3Solver::part(int n, const std::string& input_path) {
    if (n == 1) solve_part1(input_path);
    else if (n == 2) solve_part2(input_path);
}

[[maybe_unused]] static bool _reg = [] {
    SolverRegistry::add("day3", [] { return static_cast<ISolver*>(new Day3Solver()); });
    return true;
}();
