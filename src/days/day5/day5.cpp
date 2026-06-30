//
// Created by izik on 08/06/2026.
//

#include "day5.h"

#include <algorithm>
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

    reader->setInput("../inputs/day5", '\n');
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

void Day5Solver::reorderData(std::vector<std::string> lines) {
    auto it = lines.begin();
    std::string line = *it;
    std::vector<range> raw_ranges;
    while (!line.empty()) {
        uint64_t pos = line.find('-');
        uint64_t start = std::stoull(line.substr(0, pos));
        uint64_t end = std::stoull(line.substr(pos+1));
        raw_ranges.emplace_back(start, end);

        it = lines.begin();
        line = *it;
        lines.erase(it);
    }

    std::sort(raw_ranges.begin(), raw_ranges.end());
    m_ranges.push_back(raw_ranges.front());
    for (auto& range : raw_ranges) {
        auto& lastRange = m_ranges.back();
        std::cout.imbue(std::locale(""));
        std::cout << "range:     " << range.m_start << "-" << range.m_end << '\n';
        std::cout << "lastRange: " << lastRange.m_start << "-" << lastRange.m_end << '\n';
        if (lastRange.m_end + 1 >= range.m_start) {
            uint64_t newEnd = std::max(range.m_end, lastRange.m_end);
            uint64_t newStart = std::min(range.m_start, lastRange.m_start);
            lastRange.m_start = newStart;
            lastRange.m_end = newEnd;
        }
        else {
            m_ranges.push_back(range);
        }
    }

    char* endPtr = nullptr;
    for (const auto& lineId : lines) {
        m_ids.emplace_back(std::strtol(lineId.c_str(), &endPtr, 10));
    }
}

void Day5Solver::part1() const {
    uint64_t countFresh = 0;
    for (const auto id : m_ids) {
        auto it = std::upper_bound(m_ranges.begin(), m_ranges.end(), id, [](uint64_t value, const Day5Solver::range& r) {
                return value < r.m_start;
        });
        const bool isInRange = it != m_ranges.begin() && std::prev(it)->isInRange(id);
        countFresh += isInRange ? 1 : 0;
#ifdef EXTRA_DEBUG
        std::cout << "id: " << id << " isFresh: " << (isInRange ? "true" : "false") << std::endl;
#endif
    }

    std::cout << "Day5 Part1: " << countFresh << std::endl;
}

void Day5Solver::part2() const {
#ifdef EXTRA_DEBUG
        static uint16_t lineNum = 1;
        std::cout << "line: " << lineNum++ << " reachable: " << std::endl;
#endif

    std::cout << "Day5 Part2: " << 0 << std::endl;
}

} // namespace Solver

