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

    virtual void setInput(const std::string& input_path, char delimiter) = 0;
    [[nodiscard]] virtual std::vector<std::string> readInput() const = 0;
};

} // namespace Read
