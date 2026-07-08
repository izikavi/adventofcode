//
// Created by izik on 01/07/2026.
//

#pragma once

#include <cstdint>

namespace operators {

class IOperator {
public:
    IOperator() = default;
    virtual ~IOperator() = default;

    virtual void insertVal(int64_t number) = 0;
    virtual int64_t getResult() const = 0;
    virtual void reset() = 0;

    static uint32_t countDigits(int64_t number);
};

class BaseOperator : public IOperator {
public:
    explicit BaseOperator(int64_t initVal);
    ~BaseOperator() override = default;

    int64_t getResult() const override;
    void reset() override;

protected:
    int64_t m_total;
    const int64_t m_initTotal;
};


class AddOperator : public BaseOperator {
public:
    AddOperator();
    virtual ~AddOperator() = default;

    void insertVal(int64_t number) override;
};

class MultiOperator : public BaseOperator {
public:
    MultiOperator();
    virtual ~MultiOperator() = default;

    void insertVal(int64_t number) override;
};

} // namespace operatos

