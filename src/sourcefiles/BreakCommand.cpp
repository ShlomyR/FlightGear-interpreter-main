#include <string>
#include <vector>
#include <iostream>

#include "../hederfiles/BreakCommand.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/Parser.hpp"

int BreakCommand::DoCommand(std::vector<std::string> const&line)
{
    breakFunc(line);
    return 0;
}

void BreakCommand::breakFunc(std::vector<std::string> const&line)
{
    std::cout << "\nBreakCommand was called: " << line[0] << "\n"; 
    SymbolVar::getInstance()->getMapStr().at("breakLoop") = "true";
}