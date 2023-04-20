#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "../hederfiles/ConditionChecker.hpp"
#include "../hederfiles/WhileCommand.hpp"
#include "../hederfiles/SymbolVar.hpp"

bool ConditionChecker::isNumber(const std::string &str) 
{
    auto it = std::find_if_not(str.begin(), str.end(), ::isdigit);
    return it == str.end();
}

bool ConditionChecker::check(const std::vector<std::string>& line)
{
    if (line.size() < 4) {
        throw std::invalid_argument("Invalid condition");
    }
    const std::string& lhs = line[1];
    const std::string& op = line[2];
    const std::string& rhs = line[3];

    if (!isNumber(lhs) && isNumber(rhs)) {
        return checkStringNumberComparison(line, op, stod(rhs));
    } else if (isNumber(lhs) && !isNumber(rhs)) {
        return checkNumberStringComparison(line, stod(lhs), op);
    } else if (!isNumber(lhs) && !isNumber(rhs)) {
        return checkStringComparison(lhs, op, rhs);
    } else if (isNumber(lhs) && isNumber(rhs)) {
        return checkNumberComparison(stod(lhs), op, stod(rhs));
    } else {
        throw std::runtime_error("This type of checking is not suported!!!");
    }
}

bool ConditionChecker::checkComparison(const double lhs, const std::string &op, const double rhs)
{
    if (op == "<") {
        return lhs < rhs;
    } else if (op == ">") {
        return lhs > rhs;
    } else if (op == "==") {
        return lhs == rhs;
    } else if (op == "<=") {
        return lhs <= rhs;
    } else if (op == ">=") {
        return lhs >= rhs;
    } else if (op == "!=") {
        return lhs != rhs;
    } else {
        throw std::invalid_argument("Unknown comparison operator");
    }
}

bool ConditionChecker::checkStringNumberComparison(const std::vector<std::string> &line, const std::string &op, const double rhs)
{
    const double lhs = (SymbolVar::getInstance()->getMapStr().count(line[1]) > 0) ? WhileCommand::getVal(line) : WhileCommand::getVal(line[1]);
    return checkComparison(lhs, op, rhs);
}

bool ConditionChecker::checkNumberStringComparison(const std::vector<std::string> &line, const double lhs, const std::string &op)
{
    const double rhs = WhileCommand::getVal(line[3]);

    return checkComparison(lhs, op, rhs);
}

bool ConditionChecker::checkStringComparison(const std::string &lhs, const std::string &op, const std::string &rhs)
{
    return checkComparison(WhileCommand::getVal(lhs), op, WhileCommand::getVal(rhs));
}

bool ConditionChecker::checkNumberComparison(const double lhs, const std::string &op, const double rhs)
{
    return checkComparison(lhs, op, rhs);
}
