#include "../hederfiles/Expressions/ArithmeticExpression/Modulo.hpp"

double Modulo::calc() const 
{
    return (int)m_right->calc() % (int)m_left->calc();
}

// void Modulo::print(double val) const 
// {
//     std::cout << val << "\n";
// }