//
// Created by izik on 30/06/2026.
//

#include "day6.h"

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>

#include "IReader.h"
#include "IOperator.h"


namespace Solver {

Day6Solver::Day6Solver(const std::shared_ptr<Utils::IReader>& readerPtr) : ISolver(readerPtr) {
}

void Day6Solver::solve(uint8_t part) {
    std::shared_ptr<Utils::IReader> reader = m_readerWeakPtr.lock();
    if (!reader) {
        std::cerr << "Error when creating reader." << std::endl;
        return;
    }

    reader->setInput("../inputs/day6", '\n');
    auto data = reader->readInput();
    reorderData(data);

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

void Day6Solver::reorderData(std::vector<std::string> lines) {
    int lastLine = lines.size() - 1;
    for ( ; lastLine >=0 && lines[lastLine].empty(); --lastLine) {
        lines.erase(lines.end() - 1);
    }
    createOperators(lines.back());
    m_matrix.resize(m_operators.size());
    m_cephMatrix.resize(m_operators.size());

    uint64_t len = lines[0].length();
    uint64_t size = lines.size();
    for (const std::string& line : lines) {
        len = std::max(len, line.length());
        uint64_t col = 0;
        std::istringstream breakLine(line);
        uint64_t currVal = 0;
        while (breakLine >> currVal) {
            m_matrix[col].push_back(currVal);
            ++col;
        }
    }

    for (std::string& line :lines) {
        line.resize(len, ' ');
    }

    uint64_t col = 0;
    for (uint64_t i = len; i-- > 0; ) {
        std::string numStr;

        for (uint64_t row = 0; row < size; ++row) {
            char curr = lines[row][i];
            if(curr != ' ') {
                numStr += curr;
            }
        }

        if (numStr.empty()) {
            ++col;
        }
        else {
            m_cephMatrix[col].push_back(std::stoll(numStr));
        }
    }
    std::reverse(m_cephMatrix.begin(), m_cephMatrix.end());
}

void Day6Solver::createOperators(const std::string& operatorsLine) {
    for (char c : operatorsLine) {
        switch (c) {
            case '+':
                m_operators.push_back(std::make_shared<operators::AddOperator>());
                break;
            case '*':
                m_operators.push_back(std::make_shared<operators::MultiOperator>());
                break;
            default:
                // do nothing
                break;
        }
    }
}

void Day6Solver::restOperators() const {
    for (auto operatorPtr : m_operators) {
        operatorPtr->reset();
    }
}

void Day6Solver::part1() const {
    restOperators();
    uint64_t totalSum = 0;
    for (uint64_t i = 0; i < m_matrix.size(); ++i) {
        auto operatorPtr = m_operators[i];
        for (uint64_t val : m_matrix[i]) {
            operatorPtr->insertVal(val);
        }
        totalSum += operatorPtr->getResult();
#ifdef EXTRA_DEBUG
        std::cout << "i: " << i << " total: " << totalSum << std::endl;
#endif
    }

    std::cout << "Day 6 part 1: " << totalSum << std::endl;
}

void Day6Solver::part2() const {
    restOperators();
    uint64_t totalSum = 0;
    for (uint64_t i = 0; i < m_cephMatrix.size(); ++i) {
        auto operatorPtr = m_operators[i];
        for (uint64_t val : m_cephMatrix[i]) {
            operatorPtr->insertVal(val);
        }
        totalSum += operatorPtr->getResult();
#ifdef EXTRA_DEBUG
        std::cout << "i: " << i << " total: " << totalSum << std::endl;
#endif
    }

    std::cout << "Day 6 part 2: " << totalSum << std::endl;
}


} // namespace Solver

