#include "../hederfiles/Expressions/ArithmeticExpression/Multiply.hpp"

double Multiply::calc() const 
{
    return m_right->calc() * m_left->calc();
}

// void Multiply::print(double val) const 
// {
//     std::cout << val << "\n";
// }