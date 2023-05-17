#pragma once

#include "Token.hxx"

class LeftParenthesis : public Token
{
public:
    LeftParenthesis(char);
    bool isOperator() const override;
    bool isNumber() const override;
    bool isParenthesis() const override;
    int getPrecedence() const override;
    double getValue() const override;
    char getOperator() const override;
private:
    char m_value;
};
