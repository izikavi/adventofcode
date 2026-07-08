//
// Created by izik on 08/07/2026.
//

#include "day7.h"

#include <iostream>
#include <ostream>
#include <string>

#include "IReader.h"


namespace Solver {

Day7Solver::Day7Solver(const std::shared_ptr<Utils::IReader> &readerPtr) : ISolver(readerPtr) {
}

void Day7Solver::solve(uint8_t part) {
    std::shared_ptr<Utils::IReader> reader = m_readerWeakPtr.lock();
    if (!reader) {
        std::cerr << "Error when creating reader." << std::endl;
        return;
    }

    reader->setInput("../inputs/day7", '\n');
    auto data = reader->readInput();
    setInput(data);

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

void Day7Solver::reorderData(const std::vector<std::string> &input) {
}

void Day7Solver::part1() {
#ifdef EXTRA_DEBUG
#endif

    std::cout << "Day 7 Part 1: " << 0 << std::endl;
}

void Day7Solver::part2() {
    std::cout << "Day 7 Part 2: " << count << std::endl;
}

} // namespace

