//
// Created by izik on 30/06/2026.
//

#pragma once

#include <vector>
#include <cstdint>

#include "ISolver.h"

namespace operators {
class IOperator;
}

namespace Solver {

class Day6Solver : public ISolver {
public:
    explicit Day6Solver(const std::shared_ptr<Utils::IReader>& readerPtr);
    ~Day6Solver() override = default;

    void solve(uint8_t part) override;
    [[nodiscard]] uint8_t numParts() const override { return 2; }

private:
    void reorderData(std::vector<std::string> lines);
    void createOperators(const std::string& operatorsLine);
    void restOperators() const;

    void part1() const;
    void part2() const;

    std::vector<std::vector<uint64_t> > m_matrix;
    std::vector<std::vector<uint64_t> > m_cephMatrix;
    std::vector<std::shared_ptr<operators::IOperator> > m_operators;
};

}
