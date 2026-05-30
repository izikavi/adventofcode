//
// Created by izik on 28/05/2026.
//

#pragma once

#include <cstdint>
#include <memory>
#include <string>

namespace Utils {
class IReader;
}

namespace Solver {

class ISolver {
public:
    class Stub;

    explicit ISolver(const std::shared_ptr<Utils::IReader> &readerPtr);
    virtual ~ISolver() = default;

    virtual void solve(uint8_t part) = 0;
    [[nodiscard]] virtual uint8_t numParts() const = 0;

protected:
    std::weak_ptr<Utils::IReader> m_readerWeakPtr;
};

class Stub : public ISolver {
public:
    explicit Stub(const std::shared_ptr<Utils::IReader> &readerPtr);
    ~Stub() override = default;

    void solve(uint8_t part) override;
    uint8_t numParts() const override;
};

}
