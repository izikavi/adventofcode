//
// Created by izik on 28/05/2026.
//

#pragma once

#include <string>
#include <vector>

namespace Utils {
class IReader {
    public:
    virtual ~IReader() = default;

    virtual void setInput(const std::string& input_path) = 0;
    virtual std::vector<std::string> getInput() = 0;
};

} // namespace Read
