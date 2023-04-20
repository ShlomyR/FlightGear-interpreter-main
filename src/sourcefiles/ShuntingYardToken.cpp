#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <math.h>

#include "../hederfiles/ShuntingYardToken.hpp"

std::string ShuntingYardToken::infix_str;
std::vector<std::string> ShuntingYardToken::copy_line;

ShuntingYardToken::ShuntingYardToken(Type t, const std::string &s, int prec = -1, bool ra = false)
    : type{t}, str(s), precedence{prec}, rightAssociative{ra}
{}


std::deque<ShuntingYardToken> exprToTokens(const std::string &expr)
{
    std::deque<ShuntingYardToken> tokens;

    for (const auto *p = expr.c_str(); *p; ++p) {
        if (isblank(*p)) {
            // do nothing
        } else if (isdigit(*p)) {
            const auto *b = p;
            while (isdigit(*p)) {
                ++p;
            }
            const auto s = std::string(b, p);
            tokens.push_back(ShuntingYardToken{ShuntingYardToken::Type::Number, s});
            --p;
        } else {
            ShuntingYardToken::Type t = ShuntingYardToken::Type::Unknown;
            int pr = -1;
            bool ra = false;
            switch (*p) {
            default:
                break;
            case '(':
                t = ShuntingYardToken::Type::LeftParen;
                break;
            case ')':
                t = ShuntingYardToken::Type::RightParen;
                break;
            case '^':
                t = ShuntingYardToken::Type::Operator;
                pr = 4;
                ra = true;
                break;
            case '*':
                t = ShuntingYardToken::Type::Operator;
                pr = 3;
                break;
            case '/':
                t = ShuntingYardToken::Type::Operator;
                pr = 3;
                break;
            case '+':
                t = ShuntingYardToken::Type::Operator;
                pr = 2;
                break;
            case '-':
                t = ShuntingYardToken::Type::Operator;
                pr = 2;
                break;
            }
            const auto s = std::string(1, *p);
            tokens.push_back(ShuntingYardToken{t, s, pr, ra});
        }
    }
    return tokens;
}

std::deque<ShuntingYardToken> shuntingYard(const std::deque<ShuntingYardToken> &tokens)
{
    std::deque<ShuntingYardToken> queue;
    std::vector<ShuntingYardToken> stack;


    for (auto token : tokens) {
        switch (token.type) {
        case ShuntingYardToken::Type::Number:
            queue.push_back(token);
            break;

        case ShuntingYardToken::Type::Operator: {
            const auto o1 = token;

            while (!stack.empty()) {
                const auto o2 = stack.back();
                if ((!o1.rightAssociative && o1.precedence <= o2.precedence) || (o1.rightAssociative && o1.precedence < o2.precedence)) {
                    stack.pop_back();
                    queue.push_back(o2);
                    continue;
                }
                break;
            }
            stack.push_back(o1);
        }
        break;

        case ShuntingYardToken::Type::LeftParen:
            stack.push_back(token);
            break;

        case ShuntingYardToken::Type::RightParen: {
            bool match = false;

            while (!stack.empty() && stack.back().type != ShuntingYardToken::Type::LeftParen) {
                queue.push_back(stack.back());
                stack.pop_back();
                match = true;
            }

            if (!match && stack.empty()) {
                printf("RightParen error (%s)\n", token.str.c_str());
                return {};
            }
            stack.pop_back();
        }
        break;

        default:
            printf("error (%s)\n", token.str.c_str());
            return {};
        }
    }
    while (!stack.empty()) {
        if (stack.back().type == ShuntingYardToken::Type::LeftParen) {
            printf("Mismatched parentheses error\n");
            return {};
        }

        queue.push_back(std::move(stack.back()));
        stack.pop_back();
    }
    return queue;
}

double ShuntingYardToken::shuntingYardF(std::string const expr)
{
    std::string zero_init = "0";

    std::string full_expr = zero_init + expr;

    std::vector<double> stack;

    std::vector<std::string> expressions = {full_expr};

    for (std::string &expr : expressions) {
        printf("expr = %s\n", expr.c_str());

        const auto tokens = exprToTokens(expr);
        auto queue = shuntingYard(tokens);

        while (!queue.empty()) {
            std::string op;

            const auto token = queue.front();
            queue.pop_front();
            switch (token.type) {
            case ShuntingYardToken::Type::Number:
                stack.push_back(std::stoi(token.str));
                op = "Push " + token.str;
                break;

            case ShuntingYardToken::Type::Operator: {
                const auto rhs = stack.back();
                stack.pop_back();
                const auto lhs = stack.back();
                stack.pop_back();

                switch (token.str[0]) {
                default:
                    printf("Operator error [%s]\n", token.str.c_str());
                    exit(0);
                    break;
                case '^':
                    stack.push_back(static_cast<int>(pow(lhs, rhs)));
                    break;
                case '*':
                    stack.push_back(lhs * rhs);
                    break;
                case '/':
                    stack.push_back(lhs / rhs);
                    break;
                case '+':
                    stack.push_back(lhs + rhs);
                    break;
                case '-':
                    stack.push_back(lhs - rhs);
                    break;
                }
                op = "Push " + std::to_string(lhs) + " " + token.str + " " + std::to_string(rhs);
            }
            break;

            default:
                printf("Token error\n");
                exit(0);
            }
        }
    }
    return stack.back();
}

void ShuntingYardToken::strToInfix()
{
    std::string str_push_to_vec;
    for (std::string::size_type j = 0; j < ShuntingYardToken::copy_line.size() - 2; j++) {
        str_push_to_vec += ShuntingYardToken::copy_line[j + 2];
    }
    ShuntingYardToken::infix_str = str_push_to_vec;
    str_push_to_vec.clear();
}

void ShuntingYardToken::checkMinus()
{
    if (ShuntingYardToken::infix_str[0] == '-' && ShuntingYardToken::infix_str[1] == '-') {
        ShuntingYardToken::infix_str.erase(ShuntingYardToken::infix_str.begin() + 1);
        ShuntingYardToken::infix_str[0] = '+';
    }
}

std::string ShuntingYardToken::getInfix()
{
    return ShuntingYardToken::infix_str;
}
std::vector<std::string> ShuntingYardToken::getCopy()
{
    return ShuntingYardToken::copy_line;
}
void ShuntingYardToken::setInfix(std::string s)
{
    ShuntingYardToken::infix_str = s;
}
void ShuntingYardToken::setCopy(std::vector<std::string> v)
{
    ShuntingYardToken::copy_line = v;
}

void ShuntingYardToken::setCopy(std::string v,int i)
{
    ShuntingYardToken::copy_line[i] = v;
}