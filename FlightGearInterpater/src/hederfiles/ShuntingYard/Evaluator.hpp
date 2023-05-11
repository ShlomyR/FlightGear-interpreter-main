#pragma once

#include "OutputQueue.hpp"
#include "NumberExpr.hpp"
#include "Expression.hxx"
#include "Token.hxx"

#include <memory>
#include <stack>

class Evaluator {
public:
    Evaluator(std::shared_ptr<OutputQueue> );
    std::unique_ptr<Expression> evaluate();
private:
    void printToken(std::shared_ptr<Token> );
    std::shared_ptr<OutputQueue> m_output_queue;
};
