#include "../hederfiles/ParenthesisToken.hpp"

ParenthesisToken::ParenthesisToken(char c) 
: m_paren(c)
{}

bool ParenthesisToken::isOperator() const
{ 
    return false;
}

bool ParenthesisToken::isNumber() const
{ 
    return false;
}

bool ParenthesisToken::isParenthesis() const 
{ 
    return true; 
}

int ParenthesisToken::getPrecedence() const 
{ 
    return -1; 
}

double ParenthesisToken::getValue() const 
{ 
    return 0; 
}

char ParenthesisToken::getOperator() const 
{ 
    return '\0'; 
}

char ParenthesisToken::isLeftOrRight() const 
{
    return m_paren;
}
