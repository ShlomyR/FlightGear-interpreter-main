#include "../hederfiles/Token/Tokenizer.hpp"
#include "../hederfiles/Token/NumberToken.hpp"
#include "../hederfiles/Token/OperatorToken.hpp"
#include "../hederfiles/ShuntingYard/LeftParenthesis.hpp"
#include "../hederfiles/ShuntingYard/RightParenthesis.hpp"

#include <sstream>
#include <stdexcept>
#include <vector>
#include <iostream>

void printVector(std::vector<std::shared_ptr<Token>> &tokens) {
    std::cout << "\nexpr: ";
    for (const auto &token : tokens) {
        if (token->isNumber()) {
            std::cout << token->getValue() << " ";
        } else if (token->isOperator()) {
            std::cout << token->getOperator() << " ";
        } else if (token->isParenthesis()) {
            std::cout << token->getOperator() << " ";
        }
    }
}

std::vector<std::shared_ptr<Token>> Tokenizer::tokenize(const std::string& input) const
{
    std::vector<std::shared_ptr<Token>> tokens;
    std::stringstream ss(input);

    char c;
    while (ss >> c) {
        if (isdigit(c)) {
            ss.putback(c);
            double value;
            ss >> value;
            tokens.push_back(std::make_unique<NumberToken>(value));
        } else if (c == '+' || c == '*' || c == '/' || c == '^' || c == '-') {
            tokens.push_back(std::make_unique<OperatorToken>(c));
        } else if (c == '(') {
            tokens.push_back(std::make_unique<LeftParenthesis>(c));
        } else if (c == ')') {
            tokens.push_back(std::make_unique<RightParenthesis>(c));
        } else if (!isspace(c)) {
            throw std::invalid_argument("Invalid character in input");
        }
    }
    printVector(tokens);
    return tokens;
}
