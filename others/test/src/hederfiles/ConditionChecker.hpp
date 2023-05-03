#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include "WhileCommand.hpp"

class ConditionChecker {
public:
    ConditionChecker() 
    : m_whileCommand()
    {}
    
    bool check(const std::vector<std::string>&);
    bool isNumber(const std::string&);
private:
    ConditionChecker(const ConditionChecker&) = delete;
    ConditionChecker& operator=(const ConditionChecker&) = delete;

    bool checkStringNumberComparison(const std::vector<std::string> &, const std::string&, const double);
    bool checkNumberStringComparison(const std::vector<std::string> &, const double, const std::string &);
    bool checkStringComparison(const std::string &, const std::string &, const std::string &);
    bool checkNumberComparison(const double, const std::string &, const double);
    bool checkComparison(const double, const std::string &, const double);
private:
    WhileCommand m_whileCommand;
};
