//
// Created by izik on 30/05/2026.
//

#include "day3.h"

#include <iostream>
#include <ostream>
#include <string>

#include "IReader.h"


namespace Solver {

Day3Solver::Day3Solver(std::shared_ptr<Utils::IReader> readerPtr) : ISolver(readerPtr), m_position(50) {
}

void Day3Solver::solve(uint8_t part) {
    std::shared_ptr<Utils::IReader> reader = m_readerWeakPtr.lock();
    if (!reader) {
        std::cerr << "Error when creating reader." << std::endl;
        return;
    }

    reader->setInput("../inputs/day3", '\n');
    auto data = reader->readInput();
    updateInput(data);

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

void Day3Solver::updateInput(const std::vector<std::string> &input) {
    for (const auto& line : input) {
        std::vector<uint8_t> bank;
        for (const auto& b : line) {
            bank.push_back(b);
        }
        m_data.push_back(bank);
    }
}

void Day3Solver::part1() const {
    uint64_t sum = 0;
    uint32_t lineNum = 0;
    for (const auto& line : m_data) {
        uint8_t high = 0;
        uint8_t highIndx = 0;
        uint8_t low = 0;

        for (int i = 0; i < (line.size() - 1) && high < '9'; i++) {
            uint8_t digit = line[i] - '0';
            if (digit > high) {
                high = digit;
                highIndx = i;
            }
        }
        for (int i = highIndx + 1; i < line.size() && low < '9'; i++) {
            uint8_t digit = line[i] - '0';
            if (digit > low) {
                low = digit;
            }
        }
        uint64_t bb = (high * 10 + low);
        std::cout << "Line: " << ++lineNum << " maxV: " << bb << std::endl;
        sum += bb;
    }

    std::cout << "Day3 Part1: " << sum << std::endl;
}

void Day3Solver::part2() const {
    uint64_t sum = 0;
    for (const auto& line : m_data) {

    }
    std::cout << "Day3 Part2: " << sum << std::endl;
}

} // namespace

