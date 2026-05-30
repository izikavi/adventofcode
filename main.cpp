#include <iostream>
#include <string>

#include "src/SystemManager.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: aoc <day> [part]\n";
        return 1;
    }

    const std::string day = argv[1];

    AOC::SystemManager &systemManager = AOC::SystemManager::getSystemManager();

    systemManager.init(5);
    systemManager.Solve()

    return 0;
}
