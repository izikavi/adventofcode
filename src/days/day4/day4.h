//
// Created by izik on 08/06/2026.
//


#pragma once

#include <string>
#include <vector>

#include "ISolver.h"


namespace Solver {

class Day4Solver : public ISolver {
public:
    explicit Day4Solver(const std::shared_ptr<Utils::IReader>& readerPtr);
    ~Day4Solver() override = default;

    void solve(uint8_t part) override;

private:
    void part1();
    void part2();

    [[nodiscard]] bool isReachable(uint8_t row, uint8_t column) const;
    [[nodiscard]] bool isRollAt(int64_t row, int64_t column) const;
    [[nodiscard]] uint8_t countNeighboursRolls(uint8_t row, uint8_t column) const;


    static constexpr std::pair<int, int> kNeighborOffsets[8]{
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1},
    };

    std::vector<std::string> m_data;
    uint8_t m_maxOfRoll;
};

}
