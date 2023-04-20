#pragma once

#include <string>
#include <vector>

#include "Command.hxx"

class EqualMapCommand : public Command
{
public:    
    int DoCommand(std::vector<std::string> const&) override;
private:
    void updateFromDB(std::vector<std::string> const&);
    void convertFromChToNum(std::vector<std::string> const&);
};
