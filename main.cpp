#include <iostream>
#include <string>

#include "src/SystemManager.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: aoc <day> [part]\n";
        return 1;
    }

    const uint8_t day = atoi(argv[1]);
    uint8_t part = 1;
    if (argc > 2) {
        part = atoi(argv[2]);
    };

    AOC::SystemManager &systemManager = AOC::SystemManager::getSystemManager();

    systemManager.init(5);
    systemManager.Solve(day, part);

    return 0;
}
