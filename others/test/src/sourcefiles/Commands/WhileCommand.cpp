#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "../hederfiles/Commands/WhileCommand.hpp"
#include "../hederfiles/MapException.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/WhileLoop.hpp"
#include "../hederfiles/Parser/Parse.hpp"



void WhileCommand::DoCommand(std::vector<std::string> const&line)
{
    WhileLoop::whileLoop(line);
}

double WhileCommand::getVal(std::vector<std::string> const& line)
{
    return getValueFromMap(SymbolVar::getInstance()->getMapDouble(), SymbolVar::getInstance()->getMapStr().at(line[1]), "map_doubleDB");
}

double WhileCommand::getVal(std::string const& word)
{
    return getValueFromMap(SymbolVar::getInstance()->getMapDouble(), word, "map_doubleDB");
}

std::string WhileCommand::getStringVal(std::vector<std::string> const& line)
{
    return getValueFromMap(SymbolVar::getInstance()->getMapStr(), line[3], "map_strDB");
}

std::string WhileCommand::getStringVal(std::string const& word)
{
    return getValueFromMap(SymbolVar::getInstance()->getMapStr(), word, "map_strDB");
}

template<typename T>
T WhileCommand::getValueFromMap(std::unordered_map<std::string, T> const& map, std::string const& key, std::string const& mapName)
{
    T defaultValue = 0;
    try {
        if (map.count(key)) {
            return map.at(key);
        } else {
            throw MapException("Error: " + key + " not found in " + mapName + ".", std::string(__FILE__) + ":" + std::to_string(__LINE__));
        }
    } catch (const MapException& me) {
        std::cout << me.what() << " at line " << me.where() << "\n";
        return defaultValue;
    }
    return defaultValue;

}
