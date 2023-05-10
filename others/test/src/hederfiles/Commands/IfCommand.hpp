#pragma once

#include <string>
#include <vector>

#include "../hederfiles/Interfaces/Command.hxx"

class IfCommand : public Command
{
public:
    void DoCommand(std::vector<std::string> const&) override;
private:
    void ifFunc(std::string);
};
