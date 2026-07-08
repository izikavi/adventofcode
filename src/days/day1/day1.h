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

private:
    static int32_t ceilDiv(int32_t a, int32_t b);
    static int32_t floorDiv(int32_t a, int32_t b);

    void setInput(const std::vector<std::string>& input);
    void part1();
    void part2();

    std::vector<std::pair<char, int32_t>> m_data;
};

} // namespace Solver
