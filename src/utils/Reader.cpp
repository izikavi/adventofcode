//
// Created by izik on 28/05/2026.
//

#include "Reader.h"

#include <fstream>
#include <iostream>

namespace Utils {

void Reader::setInput(const std::string &input_path) {
    m_filePath = input_path;
    updateInput();
}

std::vector<std::string> Reader::readInput() const {
    return m_lines;
}

void Reader::updateInput() {
    std::ifstream f(m_filePath);
    if (!f.good()) {
        std::cerr << "Error when reading input file " << m_filePath << std::endl;
    }
    for (std::string line; std::getline(f, line);) {
        m_lines.push_back(line);
    }
}

} // Read
