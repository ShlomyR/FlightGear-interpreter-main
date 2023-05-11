#include "LeftParenthesis.hpp"

LeftParenthesis::LeftParenthesis(char c)
: m_value(c)
{}

bool LeftParenthesis::isOperator() const  
{ 
    return false; 
}

bool LeftParenthesis::isNumber() const  
{ 
    return false; 
}

bool LeftParenthesis::isParenthesis() const 
{ 
    return true; 
}

int LeftParenthesis::getPrecedence() const  
{ 
    return -1; 
}

double LeftParenthesis::getValue() const  
{ 
    return 0; 
}

char LeftParenthesis::getOperator() const  
{ 
    return m_value; 
}
