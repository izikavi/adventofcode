//
// Created by izik on 28/05/2026.
//

#pragma once

#include <cstdint>
#include <string>

namespace AOC {

class SystemManager {
public:
    class Day {
    public:
        explicit Day(uint8_t day);
        ~Day() = default;

    private:
        uint8_t m_dayNumber;
    };

    static SystemManager& getSystemManager();

    ~SystemManager() = default;

    void Solve(const Day& day);


private:
    SystemManager();

    static SystemManager instance;


};

} // AOC

