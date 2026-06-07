//
// Created by izik on 30/05/2026.
//

#include "day2.h"

#include <cmath>
#include <iostream>
#include <ostream>
#include <string>

#include "IReader.h"

namespace Solver {

Day2Solver::Day2Solver(const std::shared_ptr<Utils::IReader>& readerPtr) : ISolver(readerPtr) {
}

void Day2Solver::solve(uint8_t part) {
    std::shared_ptr<Utils::IReader> reader = m_readerWeakPtr.lock();
    if (!reader) {
        std::cerr << "Error when creating reader." << std::endl;
        return;
    }

    reader->setInput("../inputs/day2", ',');
    auto rawData = reader->readInput();
    updateInput(rawData);

    switch (part) {
        case 0:
            part1();
            part2();
            break;
        case 1:
            part1();
            break;
        case 2:
            part2();
            break;
        default:
            std::cerr << "Part " << part << " not found" << std::endl;
            break;
    }
}

void Day2Solver::part1() {
    uint64_t sum = 0;
    for (const auto& [low, high] : m_data) {
        for (uint64_t i = low; i <= high; i++) {
            sum += (isInvalid(i, true)) ? i : 0;
        }
    }

    std::cout << "Day 2 part1: " << sum << std::endl;
}

void Day2Solver::part2() {
    uint64_t sum = 0;
    for (const auto& [low, high] : m_data) {
        for (uint64_t i = low; i <= high; i++) {
            sum += (isInvalid(i, false)) ? i : 0;
        }
    }

    std::cout << "Day 2 part2: " << sum << std::endl;
}

void Day2Solver::updateInput(const std::vector<std::string>& input) {
    for (const auto& line : input) {
        uint32_t pos = line.find('-');
        char *pc{};
        uint64_t low = std::strtoull(line.substr(0, pos).c_str(), &pc, 10);
        uint64_t high = std::strtoull(line.substr(pos + 1).c_str(), &pc, 10);
        m_data.emplace_back(low, high);
    }
}

bool Day2Solver::isInvalid(uint64_t n, bool exactlyTwice) {
    std::string s = std::to_string(n);
    uint16_t len = s.size();
    if (exactlyTwice) {
        if (len % 2 != 0) {
            return false;
        }

        size_t half = len / 2;
        return s.compare(0, half, s, half, half) == 0;
    }
    for (int d = 1; d <= len / 2; ++d) {
        if (len % d) continue;

        bool ok = true;
        for (int i = d; i < len; ++i)
            if (s[i] != s[i - d]) {
                ok = false; break;
            }

        if (ok) return true;
    }
    return false;
}

} // namespace

