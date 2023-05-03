#pragma once

#include <string>
#include <vector>

#include "Command.hxx"

class ConnectCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override; 
};
