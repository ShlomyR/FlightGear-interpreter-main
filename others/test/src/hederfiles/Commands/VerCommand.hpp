#pragma once

#include <string>
#include <vector>

#include "../hederfiles/Interfaces/Command.hxx"

class VerCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
};
