#include "../hederfiles/Expressions/ArithmeticExpression/Divide.hpp"

double Divide::calc() const
{
    return m_right->calc() / m_left->calc();
}