#include "OperatorToken.hpp"

OperatorToken::OperatorToken(char c)
: m_symbol(c)
{}

bool OperatorToken::isOperator() const 
{ 
    return true; 
}

bool OperatorToken::isNumber() const 
{ 
    return false; 
}

bool OperatorToken::isParenthesis() const 
{ 
    return false; 
}

int OperatorToken::getPrecedence() const  
{ 
    if (m_symbol == '^')
        return 3;
    else if (m_symbol == '/' || m_symbol == '*')
        return 2;
    else if (m_symbol == '+' || m_symbol == '-')
        return 1;
    else
        return -1;
}

double OperatorToken::getValue() const  
{
    return m_symbol; 
}

char OperatorToken::getOperator() const  
{
    return m_symbol; 
}
