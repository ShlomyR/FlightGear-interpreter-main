#include "Evaluator.hpp"

#include <iostream>
#include <memory>

Evaluator::Evaluator(std::shared_ptr<OutputQueue> output_queue) 
: m_output_queue(output_queue)
{}

std::unique_ptr<Expression> Evaluator::evaluate() 
{
    std::stack<std::unique_ptr<Expression>>  operands;
    std::shared_ptr<Token> token;
    
    while ((token = m_output_queue->dequeue())) {
        if (token->isNumber()) {
            operands.push(std::make_unique<NumberExpr>(token->getValue()));
        } else {
            std::unique_ptr<Expression> a = std::move(operands.top());
            operands.pop();
            std::unique_ptr<Expression> b = std::move(operands.top());
            operands.pop();
            switch (token->getOperator())
            {
            case '+': // addition
                operands.push(std::make_unique<Pluse>(std::move(a), std::move(b)));
                break;
            case '-': // subtraction
                operands.push(std::make_unique<Minus>(std::move(a), std::move(b)));
                break;
            case '*': // multiplication
                operands.push(std::make_unique<Multiply>(std::move(a), std::move(b)));
                break;
            case '/': // division
                operands.push(std::make_unique<Divide>(std::move(a), std::move(b)));
                break;
            case '^': // exponent
                operands.push(std::make_unique<Power>(std::move(a), std::move(b)));
                break;
            case '%': // modulo
                operands.push(std::make_unique<Modulo>(std::move(a), std::move(b)));
                break;
                // add cases for other operators as needed
            }
        }
    }
    return std::move(operands.top());
}

void Evaluator::printToken(std::shared_ptr<Token> token)
{
    if (token->isNumber()) {
        std::cout << token->getValue() << " ";
    } else if (token->isOperator()) {
        std::cout << token->getOperator() << " ";
    } else if (token->isParenthesis()) {
        std::cout << token->getOperator() << " ";
    }
}
