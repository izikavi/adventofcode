//
// Created by izik on 30/05/2026.
//

#include "ISolver.h"

namespace Solver {
ISolver::ISolver(const std::shared_ptr<Utils::IReader> &readerPtr) : m_readerWeakPtr(readerPtr) {
}

Stub::Stub(const std::shared_ptr<Utils::IReader> &readerPtr) : ISolver(readerPtr) {
}

void Stub::solve([[maybe_unused]] uint8_t part) {
}

uint8_t Stub::numParts() const {
    return 0;
}

} // Solver
