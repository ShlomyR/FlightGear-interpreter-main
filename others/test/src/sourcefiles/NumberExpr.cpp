#include "../hederfiles/NumberExpr.hpp"

NumberExpr::NumberExpr(double val)
: m_value(val)
{}

double NumberExpr::calc() const
{
    return m_value;
}

void NumberExpr::print(double ) const
{
    std::cout << "The number is: " << m_value << "\n";
}