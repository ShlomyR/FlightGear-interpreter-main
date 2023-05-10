#pragma once

#include <stack>

#include "../hederfiles/Expressions/ArithmeticExpression/Multiply.hpp"
#include "../hederfiles/Expressions/ArithmeticExpression/Divide.hpp"
#include "../hederfiles/Expressions/ArithmeticExpression/Modulo.hpp"
#include "../hederfiles/Expressions/ArithmeticExpression/Modulo.hpp"
#include "../hederfiles/Expressions/ArithmeticExpression/Power.hpp"
#include "../hederfiles/Expressions/ArithmeticExpression/Pluse.hpp"
#include "../hederfiles/Expressions/ArithmeticExpression/Minus.hpp"
#include "../hederfiles/ShuntingYard/OutputQueue.hpp"
#include "../hederfiles/Expressions/NumberExpr.hpp"
#include "../hederfiles/Interfaces/Expression.hxx"
#include "../hederfiles/Interfaces/Token.hxx"

class Evaluator {
public:
    Evaluator(std::shared_ptr<OutputQueue> );
    std::unique_ptr<Expression> evaluate();
private:
    void printToken(std::shared_ptr<Token> );
    std::shared_ptr<OutputQueue> m_output_queue;
};
