#pragma once

#include <string>
#include <vector>

#include "../hederfiles/Interfaces/Command.hxx"

class ConnectCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override; 
};
