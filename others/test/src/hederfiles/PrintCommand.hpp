#pragma once

#include <string>
#include <vector>

#include "Command.hxx"

class PrintCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
private:
    void printFunc(std::string);
    void printCurly(std::vector<std::string> const&);
};
