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
    constexpr uint8_t NUM_OF_DIGITS = 2;
    uint64_t sum = 0;
    uint32_t lineNum = 0;
    for (const auto& line : m_data) {
        uint64_t bankJolt = highestJolt(line, NUM_OF_DIGITS);
#ifdef EXTRA_DEBUG
        std::cout << "Line: " << ++lineNum << " maxV: " << bankJolt << std::endl;
#endif

        sum += bankJolt;
    }

    std::cout << "Day3 Part1: " << sum << std::endl;
}

void Day3Solver::part2() const {
    constexpr uint8_t NUM_OF_DIGITS = 12;
    uint64_t sum = 0;
    uint32_t lineNum = 0;
    for (const auto& line : m_data) {
        uint64_t bankJolt = highestJolt(line, NUM_OF_DIGITS);
#ifdef EXTRA_DEBUG
        std::cout << "Line: " << ++lineNum << " maxV: " << bankJolt << std::endl;
#endif
        sum += bankJolt;
    }

    std::cout << "Day3 Part2: " << sum << std::endl;
}

int8_t Day3Solver::highestDigit(const std::vector<uint8_t> &input, int8_t startIndx, int8_t endIndx) {
    constexpr uint8_t MAX_DIGITS = ('9' - '0');
    uint8_t high = 0;
    int8_t indx = 0;
    for (int8_t i = startIndx; i < endIndx && high < MAX_DIGITS; i++) {
        uint8_t digit = input[i] - '0';
        if (digit > high) {
            high = digit;
            indx = i;
        }
    }

    return indx;
}

uint64_t Day3Solver::highestJolt(const std::vector<uint8_t> &input, uint8_t numOfDigits) {
    uint64_t bankJolt = 0;
    uint8_t digit = 0;
    int8_t indx = -1;
    for (uint8_t i = 0; i < numOfDigits; ++i) {
        indx = highestDigit(input, indx + 1, input.size() - (numOfDigits - i - 1));
        digit = input[indx] - '0';
        bankJolt = (bankJolt * 10) + digit;
    }

    return bankJolt;
}


} // namespace

