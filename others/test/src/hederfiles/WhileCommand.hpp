#pragma once

#include <string>
#include <vector>

#include "Command.hxx"

class WhileCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
    double getVal(std::vector<std::string> const&);
    double getVal(std::string const&);
    std::string getStringVal(std::vector<std::string> const&);
    std::string getStringVal(std::string const&);
private:
    template<typename T>
    T getValueFromMap(std::unordered_map<std::string, T> const&, std::string const&, std::string const&);
};
