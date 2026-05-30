//
// Created by izik on 28/05/2026.
//

#pragma once

#include <vector>

#include "ISolver.h"


namespace Solver {
class Day1Solver : public Solver::ISolver {
public:
    Day1Solver(std::shared_ptr<Utils::IReader> readerPtr);
    ~Day1Solver() override = default;

    void solve(uint8_t part) override;
    [[nodiscard]] uint8_t numParts() const override { return 2; }

private:
    void part1();
    void part2();

    int8_t m_position;
    std::vector<std::string> m_data;
};

} // namespace Solver
