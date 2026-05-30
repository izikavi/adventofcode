//
// Created by izik on 28/05/2026.
//

#include "day1.h"

#include <iostream>
#include <ostream>
#include <string>

#include "IReader.h"


namespace Solver {

Day1Solver::Day1Solver(std::shared_ptr<Utils::IReader> readerPtr) : ISolver(readerPtr), m_position(50) {
}

void Day1Solver::solve(uint8_t part) {
    std::shared_ptr<Utils::IReader> reader = m_readerWeakPtr.lock();
    if (!reader) {
        std::cerr << "Error when creating reader." << std::endl;
        return;
    }

    reader->setInput();
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

void Day1Solver::part1() {
    for (const auto& line : m_data) {

    }
}

void Day1Solver::part2() {
    for (const auto& line : m_data) {

    }
}

} // namespace

