#pragma once

#include "Token.hxx"

class RightParenthesis : public Token
{
public:
    RightParenthesis(char c)
    : m_value(c)
    {}
    bool isOperator() const override;
    bool isNumber() const override;
    bool isParenthesis() const override;
    int getPrecedence() const override;
    double getValue() const override;
    char getOperator() const override { return m_value; }
private:
    char m_value;
};