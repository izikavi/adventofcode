//
// Created by izik on 28/05/2026.
//

#include "SystemManager.h"

namespace AOC {

SystemManager::SystemManager() {
}

SystemManager::Day::Day(uint8_t day) : m_dayNumber(day) {
}

SystemManager & SystemManager::getSystemManager() {
    return instance;
}


void SystemManager::Solve(const Day &day) {
}

} // AOC
