//
// Created by izik on 28/05/2026.
//

#include "day1.h"

#include <iostream>
#include <ostream>
#include <string>

#include "IReader.h"


namespace Solver {

Day1Solver::Day1Solver(const std::shared_ptr<Utils::IReader> &readerPtr) : ISolver(readerPtr), m_position(50) {
}

void Day1Solver::solve(uint8_t part) {
    std::shared_ptr<Utils::IReader> reader = m_readerWeakPtr.lock();
    if (!reader) {
        std::cerr << "Error when creating reader." << std::endl;
        return;
    }

    reader->setInput("../inputs/day1");
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

void Day1Solver::setInput(const std::vector<std::string> &input) {
    for (const auto& line : input) {
        int64_t number = std::stoi(line.substr(1));
        if ('L' == line[0]) {
            number *= (-1);
        }
        m_data.emplace_back(line[0], number);
    }
}

void Day1Solver::part1() {
    uint32_t onZero = 0;
    for (const auto& [direction, steps] : m_data) {
#ifdef EXTRA_DEBUG
        std::cout << "pos:" << m_position << " direction: " << direction << ": " << steps << " counter: " << onZero << std::endl;
#endif

        m_position += steps;
        m_position = (m_position + 100) % 100;

        if (m_position == 0) {
            ++onZero;
        }
    }

    std::cout << "---------------------------------------------------\n";
    std::cout << "Day 1 Part 1: " << static_cast<int>(onZero) << std::endl;
    std::cout << "---------------------------------------------------\n";
}

void Day1Solver::part2() {
    uint32_t passZero = 0;

    for (const auto& [direction, steps] : m_data) {
#ifdef EXTRA_DEBUG
        std::cout << "pos:" << m_position << " direction: " << direction << ": " << steps << " counter: " << passZero << std::endl;
#endif
        int64_t new_pos = m_position + steps;
        passZero += abs(new_pos / 100);
        new_pos %= 100;
        if (new_pos <= 0) {
            ++passZero;
        }

        m_position = (new_pos + 100) % 100;
    }

    std::cout << "---------------------------------------------------\n";
    std::cout << "Day 1 Part 2: " << passZero << std::endl;
    std::cout << "---------------------------------------------------\n";
}

} // namespace

