#pragma once

#include "Token.hxx"

class NumberToken : public Token
{
public:
    explicit NumberToken(double);
    bool isOperator() const override;
    bool isNumber() const override;
    bool isParenthesis() const override;
    int getPrecedence() const override;
    double getValue() const override;
    char getOperator() const override;
private:
    double m_value;
};
