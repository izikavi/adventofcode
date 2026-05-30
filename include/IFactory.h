//
// Created by izik on 29/05/2026.
//

#pragma once

#include <cstdint>
#include <memory>

namespace Solver {
class ISolver;
}

namespace Utils {
class IReader;

class IFactory {
public:
    virtual ~IFactory() = default;

    virtual std::shared_ptr<IReader> createReader() = 0;
    virtual std::shared_ptr<Solver::ISolver> createSolver(uint8_t day, std::shared_ptr<IReader>) = 0;
};

}
