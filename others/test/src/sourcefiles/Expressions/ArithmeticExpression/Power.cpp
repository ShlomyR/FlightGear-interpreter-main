#include "../hederfiles/Expressions/ArithmeticExpression/Power.hpp"

double Power::calc() const
{
    return pow(m_right->calc(), m_left->calc());
}
