#include "BinaryExpr.hpp"

#include <iostream>
#include <memory>

BinaryExpr::BinaryExpr(std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
: m_left(std::move(left))
, m_right(std::move(right))
{}

void BinaryExpr::print(double val) const
{
    std::cout << val << "\n";
}
