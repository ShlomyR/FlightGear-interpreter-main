#pragma once

#include <iostream>

#include "../hederfiles/Interfaces/Expression.hxx"

class NumberExpr : public Expression
{
public:
    NumberExpr(double);
    double calc() const override;
    void print(double ) const override;
private:
    double m_value;
};
