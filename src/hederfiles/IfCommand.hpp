#pragma once

#include <string>
#include <vector>

#include "Command.hxx"

class IfCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void ifFunc(std::string);
};
