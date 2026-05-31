//
// Created by izik on 30/05/2026.
//

#pragma once

#include <string>
#include <vector>

#include "ISolver.h"


namespace Solver {

class Day3Solver : public ISolver {
public:
    explicit Day3Solver(std::shared_ptr<Utils::IReader> readerPtr);
    ~Day3Solver() override = default;

    void solve(uint8_t part) override;
    [[nodiscard]] uint8_t numParts() const override { return 2; }

private:
    void part1();
    void part2();

    int8_t m_position;
    std::vector<std::string> m_data;
};

}
