#pragma once

#include <memory>
#include <stack>
#include <vector>

#include "../hederfiles/Interfaces/Token.hxx"
#include "../hederfiles/Token/OperatorToken.hpp"
#include "../hederfiles/Token/ParenthesisToken.hpp"
#include "../hederfiles/ShuntingYard/OutputQueue.hpp"

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
