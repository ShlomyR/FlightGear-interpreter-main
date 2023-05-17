#include "NumberToken.hpp"

NumberToken::NumberToken(double value) 
: m_value(value)
{}

bool NumberToken::isOperator() const 
{ 
    return false; 
}

bool NumberToken::isNumber() const 
{ 
    return true; 
}

bool NumberToken::isParenthesis() const 
{ 
    return false; 
}

int NumberToken::getPrecedence() const  
{ 
    return -1; 
}

double NumberToken::getValue() const  
{ 
    return m_value; 
}

char NumberToken::getOperator() const  
{ 
    return '0'; 
}
