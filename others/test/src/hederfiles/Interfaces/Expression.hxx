#pragma once

class Expression
{
public:
    Expression() = default;
    virtual ~Expression() = default;
    
    virtual double calc() const = 0;
    virtual void print(double ) const = 0;
private:
    Expression(Expression const&) = delete;
    Expression& operator=(Expression const&) = delete;
};