#include "Pluse.hpp"

double Pluse::calc() const
{
    return m_right->calc() + m_left->calc();
}
