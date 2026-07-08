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

private:
    void orderData(const std::vector<std::string>& input);

    void part1();
    void part2();

    std::string m_startLine;
    std::vector<std::string> m_data;
};

} // namespace Solver
