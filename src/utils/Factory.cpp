//
// Created by izik on 29/05/2026.
//

#include "Factory.h"

#include "ISolver.h"
#include "Reader.h"
#include "../days/day1/day1.h"
#include "../days/day2/day2.h"
#include "../days/day3/day3.h"
#include "../days/day4/day4.h"
#include "../days/day5/day5.h"
#include "../days/day6/day6.h"

namespace Utils {
std::shared_ptr<IReader> Factory::createReader() {
    return std::make_shared<Reader>();
}

std::shared_ptr<Solver::ISolver> Factory::createSolver(uint8_t day, std::shared_ptr<IReader> readerPtr) {
    std::shared_ptr<Solver::ISolver> solverPtr;
    switch (day) {
        case 1:
            solverPtr = std::make_shared<Solver::Day1Solver>(readerPtr);
            break;
        case 2:
            solverPtr = std::make_shared<Solver::Day2Solver>(readerPtr);
            break;
        case 3:
            solverPtr = std::make_shared<Solver::Day3Solver>(readerPtr);
            break;
        case 4:
            solverPtr = std::make_shared<Solver::Day4Solver>(readerPtr);
            break;
        case 5:
            solverPtr = std::make_shared<Solver::Day5Solver>(readerPtr);
            break;
        case 6:
            solverPtr = std::make_shared<Solver::Day6Solver>(readerPtr);
            break;
        // case 7:
        //     solverPtr = std::make_shared<Solver::Day7Solver>(readerPtr);
        //     break;
        // case 8:
        //     solverPtr = std::make_shared<Solver::Day8Solver>(readerPtr);
        //     break;
        // case 9:
        //     solverPtr = std::make_shared<Solver::Day9Solver>(readerPtr);
        //     break;
        // case 10:
        //     solverPtr = std::make_shared<Solver::Day10Solver>(readerPtr);
        //     break;
        // case 11:
        //     solverPtr = std::make_shared<Solver::Day11Solver>(readerPtr);
        //     break;
        // case 12:
        //     solverPtr = std::make_shared<Solver::Day12Solver>(readerPtr);
        //     break;
        default:
            solverPtr = std::make_shared<Solver::ISolver::Stub>(readerPtr);
    }

    return solverPtr;
}

} // Utils
