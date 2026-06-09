//
// Created by izik on 09/06/2026.
//

#pragma once

#include <string>
#include <vector>

#include "ISolver.h"


namespace Solver {

class Day5Solver : public ISolver {
public:
    explicit Day5Solver(const std::shared_ptr<Utils::IReader>& readerPtr);
    ~Day5Solver() override = default;

    void solve(uint8_t part) override;
    [[nodiscard]] uint8_t numParts() const override { return 2; }

private:
    void part1();
    void part2();

    std::vector<std::string> m_data;
};

}
