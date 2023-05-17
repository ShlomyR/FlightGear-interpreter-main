#include "Modulo.hpp"

double Modulo::calc() const 
{
    return (int)m_right->calc() % (int)m_left->calc();
}
