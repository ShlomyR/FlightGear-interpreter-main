#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>


class ConditionChecker {
public:
    ConditionChecker() {}
    bool check(const std::vector<std::string>&);
    bool isNumber(const std::string&);
private:
    ConditionChecker(const ConditionChecker&) = delete;
    ConditionChecker& operator=(const ConditionChecker&) = delete;

    bool checkStringNumberComparison(const std::vector<std::string> &, const std::string&, const double);
    bool checkNumberStringComparison(const std::vector<std::string> &, const double, const std::string &);
    bool checkStringComparison(const std::string &lhs, const std::string &op, const std::string &rhs);
    bool checkNumberComparison(const double lhs, const std::string &op, const double rhs);
    bool checkComparison(const double, const std::string &, const double);
};
