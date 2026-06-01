//
// Created by izik on 28/05/2026.
//

#include "day1.h"

#include <iostream>
#include <ostream>
#include <string>

#include "IReader.h"


namespace Solver {

Day1Solver::Day1Solver(const std::shared_ptr<Utils::IReader> &readerPtr) : ISolver(readerPtr) {
}

void Day1Solver::solve(uint8_t part) {
    std::shared_ptr<Utils::IReader> reader = m_readerWeakPtr.lock();
    if (!reader) {
        std::cerr << "Error when creating reader." << std::endl;
        return;
    }

    reader->setInput("../inputs/day1", '\n');
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
        int32_t number = std::stoi(line.substr(1));
        if ('L' == line[0]) {
            number *= (-1);
        }
        m_data.emplace_back(line[0], number);
    }
}

void Day1Solver::part1() {
    uint32_t onZero = 0;
    int32_t position = 50;
    for (const auto& [direction, steps] : m_data) {
#ifdef EXTRA_DEBUG
        std::cout << "pos:" << position << " direction: " << direction << ": " << steps << " counter: " << onZero << std::endl;
#endif

        position += steps;
        position = (position + 100) % 100;

        if (position == 0) {
            ++onZero;
        }
    }

    std::cout << "---------------------------------------------------\n";
    std::cout << "Day 1 Part 1: " << static_cast<int>(onZero) << std::endl;
    std::cout << "---------------------------------------------------\n";
}

int32_t Day1Solver::floorDiv(int32_t a, int32_t b) {
    int32_t q = a / b;
    if (a % b != 0 && a < 0) {
        --q;
    }

    return q;
}
int32_t Day1Solver::ceilDiv(int32_t a, int32_t b) {
    int32_t q = a / b;
    if (a % b != 0 && a > 0) {
        ++q;
    }

    return q;
}

void Day1Solver::part2() {
    int32_t oldPosition = 50;
    int32_t count = 0;

    for (const auto& [direction, steps] : m_data) {
        int32_t nextPosition = oldPosition + steps;
        if (direction == 'R') {
            count += floorDiv(nextPosition, 100) - floorDiv(oldPosition, 100);
        }
        else if (direction == 'L') {
            count += ceilDiv(oldPosition, 100)  - ceilDiv(nextPosition, 100);
        }
        oldPosition = nextPosition;
    }

    std::cout << "---------------------------------------------------\n";
    std::cout << "Day 1 Part 2: " << count << std::endl;
    std::cout << "---------------------------------------------------\n";
}

} // namespace

