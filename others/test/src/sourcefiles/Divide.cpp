#include "../hederfiles/Divide.hpp"


double Divide::calc() const
{
    return m_right->calc() / m_left->calc();
}

// void Divide::print(double val) const
// {
//     std::cout << val << "\n";
// }