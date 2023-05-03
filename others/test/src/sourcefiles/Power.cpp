#include "../hederfiles/Power.hpp"

double Power::calc() const
{
    return pow(m_right->calc(), m_left->calc());
}

// void Power::print(double val) const
// {
//     std::cout << val << "\n";
// }