#pragma once

#include <stack>

#include "OutputQueue.hpp"
#include "Token.hxx"
#include "Expression.hxx"
#include "NumberExpr.hpp"
#include "Multiply.hpp"
#include "Minus.hpp"
#include "Divide.hpp"
#include "Modulo.hpp"
#include "Power.hpp"
#include "Pluse.hpp"
#include "Modulo.hpp"

class Evaluator {
public:
    Evaluator(std::shared_ptr<OutputQueue> output_queue);
    std::unique_ptr<Expression> evaluate();
private:
    void printToken(std::shared_ptr<Token> token);
    std::shared_ptr<OutputQueue> m_output_queue;
};
