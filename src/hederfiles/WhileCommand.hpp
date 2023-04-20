#pragma once

#include <string>
#include <vector>

#include "Command.hxx"

class WhileCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
    static double getVal(std::vector<std::string> const&);
    static double getVal(std::string const&);
    static std::string getStringVal(std::vector<std::string> const&);
    static std::string getStringVal(std::string const&);
};
