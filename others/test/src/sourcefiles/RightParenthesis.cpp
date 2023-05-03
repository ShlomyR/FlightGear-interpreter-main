#include "../hederfiles/RightParenthesis.hpp"

bool RightParenthesis::isOperator() const  
{ 
    return false; 
}

bool RightParenthesis::isNumber() const  
{ 
    return false; 
}

bool RightParenthesis::isParenthesis() const 
{ 
    return true; 
}

int RightParenthesis::getPrecedence() const  
{ 
    return -1; 
}

double RightParenthesis::getValue() const  
{ 
    return 0; 
}