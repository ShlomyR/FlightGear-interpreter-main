#include "Minus.hpp"

double Minus::calc() const
{
    return m_right->calc() - m_left->calc();
}
