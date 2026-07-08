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
    explicit Day2Solver(const std::shared_ptr<Utils::IReader>& readerPtr);
    ~Day2Solver() override = default;

    void solve(uint8_t part) override;

private:
    void part1() const;
    void part2() const;

    void updateInput(const std::vector<std::string>& input);
    static bool isInvalid(uint64_t n, bool exactlyTwice);

    std::vector<std::pair<uint64_t, uint64_t> > m_data;
};

}
