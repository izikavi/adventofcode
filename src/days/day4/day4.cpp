//
// Created by izik on 08/06/2026.
//

#include "day4.h"

#include <iostream>
#include <string>

#include "IReader.h"


namespace Solver {

Day4Solver::Day4Solver(const std::shared_ptr<Utils::IReader>& readerPtr) : ISolver(readerPtr), m_maxOfRoll(0) {
}

void Day4Solver::solve(uint8_t part) {
    std::shared_ptr<Utils::IReader> reader = m_readerWeakPtr.lock();
    if (!reader) {
        std::cerr << "Error when creating reader." << std::endl;
        return;
    }

    reader->setInput("../inputs/day4", '\n');
    m_data = reader->readInput();


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

void Day4Solver::part1() {
    m_maxOfRoll = 4;
    uint64_t countReachable = 0;
    for (uint64_t i = 0; i < m_data.size(); ++i) {
        for (uint64_t j = 0; j < m_data[i].size(); ++j) {
            if (isReachable(i, j)) {
                ++countReachable;
            }
        }
#ifdef EXTRA_DEBUG
        static uint16_t lineNum = 1;
        std::cout << "line: " << lineNum++ << "reachable: " << countReachable << std::endl;
#endif
    }

    std::cout << "Day4 Part1: " << countReachable << std::endl;
}

void Day4Solver::part2() {
    m_maxOfRoll = 4;
    uint64_t countReachable = 0;
    std::vector<std::pair<uint64_t, uint64_t>> reach{{0,0}};
    while (!reach.empty()) {
        reach.clear();
        for (uint64_t i = 0; i < m_data.size(); ++i) {
            for (uint64_t j = 0; j < m_data[i].size(); ++j) {
                if (isReachable(i, j)) {
                    ++countReachable;
                    reach.emplace_back(i,j);
                }
            }
        }

#ifdef EXTRA_DEBUG
        static uint16_t lineNum = 1;
        std::cout << "line: " << lineNum++ << " reachable: " << reach.size() << std::endl;
#endif
        for (const auto& [row, column] : reach) {
            m_data[row][column] = '.';
        }
    };

    std::cout << "Day4 Part2: " << countReachable << std::endl;
}

bool Day4Solver::isReachable(uint8_t row, uint8_t column) const {
    return (isRollAt(row, column) && countNeighboursRolls(row, column) < m_maxOfRoll);
}

bool Day4Solver::isRollAt(int64_t row, int64_t column) const {
    if (row < 0 || row >= static_cast<int64_t>(m_data.size())) {
        return false;
    }

    if (column < 0 || column >= static_cast<int64_t>(m_data.at(row).size())) {
        return false;
    }

    return (m_data.at(row).at(column) == '@');
}

uint8_t Day4Solver::countNeighboursRolls(uint8_t row, uint8_t column) const {
    uint8_t neighboursRolls = 0;
    for (const auto& [rowOffset, colOffset] : kNeighborOffsets) {
        if (isRollAt(row + rowOffset, column + colOffset)) {
            ++neighboursRolls;
        }
    }

    return neighboursRolls;
}

} // namespace Solver

