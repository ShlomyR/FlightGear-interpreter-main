#pragma once

#include "Command.hxx"

#include <string>
#include <vector>

class OpenServerCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
};
