//
// Created by izik on 29/05/2026.
//

#pragma once

#include "IFactory.h"

namespace Utils {

class Factory : public IFactory{
public:
    Factory() = default;
    ~Factory() override = default;

    std::shared_ptr<IReader> createReader() override;
    std::shared_ptr<Solver::ISolver> createSolver(uint8_t day, std::shared_ptr<IReader>) override;
};

} // Utils
