//
// Created by izik on 30/05/2026.
//

#pragma once

#include <string>
#include <vector>

#include "ISolver.h"


namespace Solver {

class Day2Solver : public ISolver {
public:
    explicit Day2Solver(std::shared_ptr<Utils::IReader> readerPtr);
    ~Day2Solver() override = default;

    void solve(uint8_t part) override;
    [[nodiscard]] uint8_t numParts() const override { return 2; }

private:
    void part1();
    void part2();

    void updateInput(std::vector<std::string> input);

    std::vector<std::pair<std::string, std::string> > m_data;
};

}
