#pragma once
#include "ISolver.h"

class Day2Solver : public ISolver {
public:
    void part(int n, const std::string& input_path) override;
    int numParts() const override { return 2; }
};
