#pragma once

#include <string>
#include <vector>

#include "Command.hxx"

class SleepCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void sleepFunc(std::string);
};
