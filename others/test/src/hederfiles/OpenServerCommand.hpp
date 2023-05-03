#pragma once

#include <string>
#include <vector>

#include "Command.hxx"

class OpenServerCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
};
