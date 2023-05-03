#pragma once

#include <iostream>

#include "Expression.hxx"

class NumberExpr : public Expression
{
public:
    NumberExpr(double val);
    double calc() const override;
    void print(double ) const override;
private:
    double m_value;
};
