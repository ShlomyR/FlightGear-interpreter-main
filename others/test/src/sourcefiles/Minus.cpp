#include "../hederfiles/Minus.hpp"


double Minus::calc() const
{
    return m_right->calc() - m_left->calc();
}

// void Minus::print(double val) const
// {
//     std::cout << val << "\n";
// }