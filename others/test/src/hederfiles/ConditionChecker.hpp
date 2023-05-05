#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <unordered_map>

#include "WhileCommand.hpp"

class ConditionChecker {
public:
    ConditionChecker();
    
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

    bool less_than(const double lhs, const double rhs);
    bool greater_than(const double lhs, const double rhs);
    bool equal_to(const double lhs, const double rhs);
    bool less_than_or_equal_to(const double lhs, const double rhs);
    bool greater_than_or_equal_to(const double lhs, const double rhs);
    bool not_equal_to(const double lhs, const double rhs);

    void initMap();
private:
    WhileCommand m_whileCommand;
    std::unordered_map<std::string, bool (ConditionChecker::*)(const double, const double)> m_comparison_map;
};
