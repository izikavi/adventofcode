//
// Created by izik on 28/05/2026.
//

#include "SystemManager.h"

#include <iostream>
#include <ostream>

#include "ISolver.h"
#include "utils/Factory.h"

namespace AOC {

SystemManager::SystemManager() : m_init(false) {
}

void SystemManager::init(uint8_t maxDay) {
    m_factoryPtr = std::make_shared<Utils::Factory>();
    m_readerPtr = m_factoryPtr->createReader();

    for (int i = 0; i < maxDay; i++) {
        m_daySolversPtr.emplace_back(m_factoryPtr->createSolver(i, m_readerPtr));
    }

    m_init = true;
}

void SystemManager::Solve(uint8_t day, uint8_t part) {
    if (!m_init) {
        std::cerr << "SystemManager::init() called" << std::endl;
        return;
    }

    if (day > m_daySolversPtr.size()) {
        std::cerr << "SystemManager::Solve() called" << std::endl;
        return;
    }

    m_daySolversPtr[day - 1]->solve(part);
}

} // AOC
