#pragma once

#include "Token.hxx"
#include "OperatorToken.hpp"
#include "ParenthesisToken.hpp"
#include "OutputQueue.hpp"

#include <memory>
#include <stack>
#include <vector>

class ShuntingYard
{
public:
    std::shared_ptr <OutputQueue> shunt(const std::vector<std::shared_ptr<Token>> &) const;
private:
    void handleOperator(const OperatorToken &, std::stack<std::shared_ptr<Token>> &, OutputQueue &) const;
    void handleParenthesis(const ParenthesisToken &, std::stack<std::shared_ptr<Token>> &, OutputQueue &) const;
    void handleMinusOperator(std::shared_ptr<Token> &, const std::shared_ptr<Token> &, const std::shared_ptr<Token> &, OperatorToken &, std::stack<std::shared_ptr<Token>> &, OutputQueue &) const;
    void handleInputAndPushToStack(const std::vector<std::shared_ptr<Token>> &, std::shared_ptr<OutputQueue> &, std::stack<std::shared_ptr<Token>> &) const;
    void emptyStackAndUpdateQueue(std::stack<std::shared_ptr<Token>> &, std::shared_ptr<OutputQueue> &) const;
};
