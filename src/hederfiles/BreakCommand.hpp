#pragma once

#include <string>
#include <vector>

#include "../hederfiles/Command.hxx"

class BreakCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void breakFunc(std::vector<std::string> const&);
};
