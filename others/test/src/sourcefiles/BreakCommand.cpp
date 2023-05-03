#include <string>
#include <vector>
#include <iostream>

#include "../hederfiles/BreakCommand.hpp"
#include "../hederfiles/MapException.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/Parse.hpp"

void BreakCommand::DoCommand(std::vector<std::string> const&line)
{
    breakFunc(line);
}

void BreakCommand::breakFunc(std::vector<std::string> const&)
{
    if ( SymbolVar::getInstance()->getMapStr().count("breakLoop")) {
        SymbolVar::getInstance()->getMapStr().at("breakLoop") = "true";
    } else {
        throw MapException("Error: " + std::string("breakLoop") + " not found in map_strDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
    }
}