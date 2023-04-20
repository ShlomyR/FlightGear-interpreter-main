#pragma once

#include <string>
#include <vector>

#include "Command.hxx"

class ConnectCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override; 
};
