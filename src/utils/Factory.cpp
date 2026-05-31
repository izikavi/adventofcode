//
// Created by izik on 29/05/2026.
//

#include "Factory.h"

#include "ISolver.h"
#include "Reader.h"
#include "../days/day1/day1.h"
#include "../days/day2/day2.h"
#include "../days/day3/day3.h"


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
        // case 4:
        //     solverPtr = std::make_shared<Day4Solver>();
        //     break;
        // case 5:
        //     solverPtr = std::make_shared<Day5Solver>();
        //     break;
        default:
            solverPtr = std::make_shared<Solver::ISolver::Stub>(readerPtr);
    }

    return solverPtr;
}

} // Utils