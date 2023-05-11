#include "Multiply.hpp"

double Multiply::calc() const 
{
    return m_right->calc() * m_left->calc();
}
