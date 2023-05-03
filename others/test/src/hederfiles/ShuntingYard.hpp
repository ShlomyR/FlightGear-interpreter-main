#pragma once

#include <memory>
#include <stack>
#include <vector>

#include "Token.hxx"
#include "OperatorToken.hpp"
#include "ParenthesisToken.hpp"
#include "OutputQueue.hpp"

class ShuntingYard
{
public:
    std::shared_ptr <OutputQueue> shunt(const std::vector<std::shared_ptr<Token>> &input) const;

private:
    void handleOperator(const OperatorToken &, std::stack<std::shared_ptr<Token>> &, OutputQueue &) const;
    void handleParenthesis(const ParenthesisToken &, std::stack<std::shared_ptr<Token>> &, OutputQueue &) const;
};
