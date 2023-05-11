#include "Power.hpp"

#include <cmath>

double Power::calc() const
{
    return pow(m_right->calc(), m_left->calc());
}
