#include "day2.h"
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

enum CubeColor { BLUE = 0, RED = 1, GREEN = 2 };

const int MAX_BLUE  = 14;
const int MAX_RED   = 12;
const int MAX_GREEN = 13;

std::vector<std::string> break_into_rounds(const std::string& line) {
    std::vector<std::string> rounds;
    size_t start = line.find(':') + 1;
    while (start != std::string::npos) {
        size_t end = line.find(';', start);
        rounds.push_back(line.substr(start, end - start));
        start = (end == std::string::npos) ? end : end + 1;
    }
    return rounds;
}

std::vector<int> max_cubes(const std::vector<std::string>& rounds) {
    std::vector<int> maxima = {0, 0, 0};
    for (const auto& round : rounds) {
        size_t pos = 0;
        while (pos < round.size()) {
            size_t num_end = round.find(' ', pos + 1);
            if (num_end == std::string::npos) break;
            int count = std::stoi(round.substr(pos, num_end - pos));
            char color_first = round.at(num_end + 1);
            pos = round.find(' ', num_end + 1);

            int idx = -1;
            if      (color_first == 'b') idx = BLUE;
            else if (color_first == 'r') idx = RED;
            else if (color_first == 'g') idx = GREEN;

            if (idx >= 0 && count > maxima[idx])
                maxima[idx] = count;
        }
    }
    return maxima;
}

int get_game_id(const std::string& line) {
    size_t colon = line.find(':');
    size_t space = line.find(' ');
    return std::stoi(line.substr(space + 1, colon - space - 1));
}

void solve_part1(const std::string& input_path) {
    auto data = read_lines(input_path);
    int sum = 0;
    for (const auto& line : data) {
        auto rounds = break_into_rounds(line);
        auto maxima = max_cubes(rounds);
        if (maxima[BLUE] <= MAX_BLUE && maxima[RED] <= MAX_RED && maxima[GREEN] <= MAX_GREEN)
            sum += get_game_id(line);
    }
    std::cout << sum << '\n';
}

void solve_part2(const std::string& input_path) {
    auto data = read_lines(input_path);
    int sum = 0;
    for (const auto& line : data) {
        auto rounds = break_into_rounds(line);
        auto maxima = max_cubes(rounds);
        sum += maxima[BLUE] * maxima[RED] * maxima[GREEN];
    }
    std::cout << sum << '\n';
}

} // namespace

void Day2Solver::part(int n, const std::string& input_path) {
    if (n == 1) solve_part1(input_path);
    else if (n == 2) solve_part2(input_path);
}

[[maybe_unused]] static bool _reg = [] {
    SolverRegistry::add("day2", [] { return static_cast<ISolver*>(new Day2Solver()); });
    return true;
}();
