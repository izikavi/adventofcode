//
// Created by izik on 08/07/2026.
//

#pragma once

#include <string>
#include <vector>

#include "ISolver.h"


namespace Solver {

class Day7Solver : public ISolver {
public:
    Day7Solver(const std::shared_ptr<Utils::IReader> &readerPtr);
    ~Day7Solver() override = default;

    void solve(uint8_t part) override;
    [[nodiscard]] uint8_t numParts() const override { return 2; }

private:
    void reorderData(const std::vector<std::string>& input);

    void part1();
    void part2();

    std::vector<std::pair<char, int32_t>> m_data;
};

} // namespace Solver
