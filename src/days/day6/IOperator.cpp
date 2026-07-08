//
// Created by izik on 01/07/2026.
//

#include "IOperator.h"

namespace operators {


BaseOperator::BaseOperator(int64_t initVal) : m_total(initVal), m_initTotal(initVal) {
}

void BaseOperator::reset() {
    m_total = m_initTotal;
}

int64_t BaseOperator::getResult() const {
    return m_total;
}

AddOperator::AddOperator() : BaseOperator(0) {
}

void AddOperator::insertVal(int64_t number) {
    m_total += number;
}

MultiOperator::MultiOperator() : BaseOperator(1) {
}

void MultiOperator::insertVal(int64_t number) {
    m_total *= number;
}


} // namespace operators

