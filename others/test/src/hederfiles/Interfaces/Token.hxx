#pragma once

class Token
{
public:
    virtual ~Token() = default;
    
    virtual bool isOperator() const = 0;
    virtual bool isNumber() const = 0;
    virtual bool isParenthesis() const = 0;
    virtual int getPrecedence() const = 0;
    virtual double getValue() const = 0;
    virtual char getOperator() const = 0;
};

