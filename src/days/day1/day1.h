//
// Created by izik on 28/05/2026.
//

#pragma once

#include <string>
#include <vector>

#include "ISolver.h"


namespace Solver {

class Day1Solver : public ISolver {
public:
    Day1Solver(const std::shared_ptr<Utils::IReader> &readerPtr);
    ~Day1Solver() override = default;

    void solve(uint8_t part) override;
    [[nodiscard]] uint8_t numParts() const override { return 2; }

private:
    void setInput(const std::vector<std::string>& input);
    void part1();
    void part2();

    int64_t m_position;
    std::vector<std::pair<char, int64_t>> m_data;
};

} // namespace Solver
