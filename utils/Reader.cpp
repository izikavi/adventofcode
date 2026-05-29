//
// Created by izik on 28/05/2026.
//

#include "Reader.h"

#include <fstream>

namespace Utils {

void Reader::setInput(const std::string &input_path) {
    m_filePath = input_path;
    updateInput();
}

std::vector<std::string> Reader::getInput() {
    return m_lines;
}

void Reader::updateInput() {
    std::ifstream f(m_filePath);
    for (std::string line; std::getline(f, line);) {
        m_lines.push_back(line);
    }
}

} // Read