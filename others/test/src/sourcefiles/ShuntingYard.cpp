#include "../hederfiles/NumberToken.hpp"
#include "../hederfiles/ShuntingYard.hpp"
#include "../hederfiles/ParenthesisToken.hpp"

#include <stack>
#include <iostream>

void printQueue(std::shared_ptr<OutputQueue> &outputQueue) {
    while (!outputQueue->isEmpty()) {
        std::cout << outputQueue->dequeue()->getValue() << " ";
    }
    std::cout << "\n";
}


std::shared_ptr<OutputQueue> ShuntingYard::shunt(const std::vector<std::shared_ptr<Token>> &input) const
{
    auto outputQueue = std::make_shared<OutputQueue>();
    std::stack<std::shared_ptr<Token>> operatorStack;
    std::shared_ptr<Token> prevToken = nullptr;
    const auto &firstToken = input.front();
    for (const auto &token : input) {
        if (token->isNumber()) {
            outputQueue->enqueue(token);
        } else if (token->isOperator()) {
            auto op = static_cast<const OperatorToken &>(*token);
            if (op.getOperator() == '-' ) {
                if (token == firstToken ) {
                    outputQueue->enqueue(std::make_shared<NumberToken>(0));
                }  else if (prevToken && prevToken->getOperator() == '-' ) {
                    operatorStack.pop();
                    op = static_cast<const OperatorToken &>('+');
                } 
            }
            handleOperator(op, operatorStack, *outputQueue);
        } else if (token->isParenthesis()) {
            const auto &paren = static_cast<const ParenthesisToken &>(*token);
            handleParenthesis(paren, operatorStack, *outputQueue);
        }
        prevToken = token;
    }
    while (!operatorStack.empty()) {
        outputQueue->enqueue(operatorStack.top());
        operatorStack.pop();
    }
    return outputQueue;
}

void ShuntingYard::handleOperator(const OperatorToken &op, std::stack<std::shared_ptr<Token>> &operatorStack, OutputQueue &outputQueue) const
{
    while (!operatorStack.empty() && operatorStack.top()->isOperator()) {
        const auto &topOp = static_cast<const OperatorToken &>(*operatorStack.top());
        if ((op.getPrecedence() <= topOp.getPrecedence()) && (topOp.getPrecedence() > 0)) {
            outputQueue.enqueue(std::move(operatorStack.top()));
            operatorStack.pop();
        } else {
            break;
        }
    }
    
    operatorStack.push(std::make_unique<OperatorToken>(op));
}

void ShuntingYard::handleParenthesis(const ParenthesisToken &paren, std::stack<std::shared_ptr<Token>> &operatorStack, OutputQueue &outputQueue) const
{
    if (paren.isLeftOrRight() == '(') {
        operatorStack.push(std::make_shared<ParenthesisToken>(paren));
    } else if (paren.isLeftOrRight() == ')') {
        while (!operatorStack.empty() ) {
            const auto& top = static_cast<const ParenthesisToken&>(*operatorStack.top());
            if (top.isLeftOrRight() == '(') {
                operatorStack.pop();
                break;
            }
            else {
                outputQueue.enqueue(std::move(operatorStack.top()));
                operatorStack.pop();
            }
        }
    }
}
