#pragma once

#include "Expression.hxx"

#include <iostream>
#include <memory>

class BinaryExpr : public Expression
{
public:
    BinaryExpr(std::unique_ptr<Expression>, std::unique_ptr<Expression>);
    void print(double val) const override;
protected:
    std::unique_ptr<Expression> m_left;
    std::unique_ptr<Expression> m_right;
};
