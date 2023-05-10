#pragma once

#include <string>
#include <vector>

#include "../hederfiles/Interfaces/Command.hxx"

class BreakCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
private:
    void breakFunc(std::vector<std::string> const&);
};
