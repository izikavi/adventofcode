//
// Created by izik on 28/05/2026.
//

#pragma once

#include <cstdint>
#include <string>

namespace Solver {

class ISolver {
public:
    virtual void part(int n, const std::string& input_path) = 0;
    [[nodiscard]] virtual uint8_t numParts() const = 0;
    virtual ~ISolver() = default;
};

}
