//
// Created by izik on 30/05/2026.
//

#include <iostream>

#include "ISolver.h"

namespace Solver {
ISolver::ISolver(const std::shared_ptr<Utils::IReader> &readerPtr) : m_readerWeakPtr(readerPtr) {
}

ISolver::Stub::Stub(const std::shared_ptr<Utils::IReader> &readerPtr) : ISolver(readerPtr) {
}

void ISolver::Stub::solve([[maybe_unused]] uint8_t part) {
    std::cout << "This is Stub!!!\n";
}

uint8_t ISolver::Stub::numParts() const {
    return 0;
}

} // Solver
