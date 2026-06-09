//
// Created by izik on 08/06/2026.
//

#include "day5.h"

#include <iostream>
#include <string>

#include "IReader.h"


namespace Solver {

Day5Solver::Day5Solver(const std::shared_ptr<Utils::IReader>& readerPtr) : ISolver(readerPtr) {
}

void Day5Solver::solve(uint8_t part) {
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

void Day5Solver::part1() {
    uint64_t countReachable = 0;
    for (uint64_t i = 0; i < m_data.size(); ++i) {
#ifdef EXTRA_DEBUG
#endif
    }

    std::cout << "Day4 Part1: " << countReachable << std::endl;
}

void Day5Solver::part2() {
#ifdef EXTRA_DEBUG
        static uint16_t lineNum = 1;
        std::cout << "line: " << lineNum++ << " reachable: " << reach.size() << std::endl;
#endif

    std::cout << "Day4 Part2: " << 0 << std::endl;
}

} // namespace Solver

