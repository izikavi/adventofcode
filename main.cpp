#include <iostream>
#include <string>
#include "ISolver.h"
#include "SolverRegistry.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: aoc <day> [part]\n";
        return 1;
    }

    const std::string day = argv[1];

    return 0;
}
