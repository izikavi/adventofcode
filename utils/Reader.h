//
// Created by izik on 28/05/2026.
//

#pragma once

#include "IReader.h"

namespace Utils {
class Reader : public IReader {
public:
    Reader() = default;
    ~Reader() override = default;

    void setInput(const std::string& input_path) override;
    std::vector<std::string> getInput() override;

private:
    void updateInput();
    std::string m_filePath;
    std::vector<std::string> m_lines;
};

} // Read

