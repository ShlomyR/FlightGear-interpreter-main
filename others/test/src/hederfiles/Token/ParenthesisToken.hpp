#pragma once

#include "../hederfiles/Interfaces/Token.hxx"

class ParenthesisToken : public Token
{
public:
    ParenthesisToken(char);
    bool isOperator() const override;
    bool isNumber() const override;
    bool isParenthesis() const override;
    int getPrecedence() const override;
    double getValue() const override;
    char getOperator() const override;
    char isLeftOrRight() const;
private:
    char m_paren;
};