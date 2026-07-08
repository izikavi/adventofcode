//
// Created by izik on 09/06/2026.
//

#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "ISolver.h"


namespace Solver {

class Day5Solver : public ISolver {
public:
    explicit Day5Solver(const std::shared_ptr<Utils::IReader>& readerPtr);
    ~Day5Solver() override = default;

    void solve(uint8_t part) override;

    struct Range {
        uint64_t m_start;
        uint64_t m_end;

        Range(uint64_t start, uint64_t end) : m_start(start), m_end(end) {}
        ~Range() = default;

        [[nodiscard]] bool isInRange(uint64_t val) const {
            return val >= m_start && val <= m_end;
        };

        [[nodiscard]] uint64_t count() const {
#ifdef EXTRA_DEBUG
            std::cout << "start: " << m_start << " end: " << m_end << std::endl;
#endif
            return (m_end - m_start + 1);
        }

        bool operator<(const Range& rhs) const {
            // if (m_start == rhs.m_start) {
            //     return m_end < rhs.m_end;
            // }
            return m_start < rhs.m_start;
        }
    };
private:
    void reorderData(std::vector<std::string> lines);
    void part1() const;
    void part2() const;

    std::vector<Range> m_ranges;
    std::vector<uint64_t> m_ids;
};

}
