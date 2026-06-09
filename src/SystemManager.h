//
// Created by izik on 28/05/2026.
//

#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "IFactory.h"
#include "IReader.h"

namespace Solver {
class ISolver;
}

namespace AOC {

class SystemManager {
public:
    static SystemManager& getSystemManager() {
        static SystemManager inst;
        return inst;
    }

    ~SystemManager() = default;

    SystemManager(const SystemManager&) = delete;
    void operator=(const SystemManager&) = delete;

    void init(uint8_t maxDay);
    void Solve(uint8_t day, uint8_t part = 0) const;


private:
    SystemManager();

    bool m_init;
    std::shared_ptr<Utils::IFactory> m_factoryPtr;
    std::shared_ptr<Utils::IReader> m_readerPtr;
    std::vector<std::shared_ptr<Solver::ISolver> > m_daySolversPtr;

};

} // AOC

