#include "../hederfiles/Pluse.hpp"

double Pluse::calc() const
{
    return m_right->calc() + m_left->calc();
}

// void Pluse::print(double val) const
// {
//     std::cout << val << "\n";
// }