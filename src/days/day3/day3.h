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
    void updateInput(const std::vector<std::string>& input);
    void part1() const;
    void part2() const;

    int8_t m_position;
    std::vector<std::vector<uint8_t> > m_data;
};

}
