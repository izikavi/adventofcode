//
// Created by izik on 09/06/2026.
//

#pragma once

#include <vector>

#include "ISolver.h"
#include "IOperand.h"

namespace Solver {

class Day6Solver : public ISolver {
public:
    explicit Day6Solver(const std::shared_ptr<Utils::IReader>& readerPtr);
    ~Day6Solver() override = default;

    void solve(uint8_t part) override;
    [[nodiscard]] uint8_t numParts() const override { return 2; }

private:
    void reorderData(std::vector<std::string> lines);
    void part1() const;
    void part2() const;

    std::vector<std::vector<uint64_6> > m_problems;
    std::vector<std::shared_ptr<IOperand> > m_operators;
};

}
