#include <string>
#include <vector>

#include "../hederfiles/WhileCommand.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/WhileLoop.hpp"
#include "../hederfiles/Parser.hpp"

int WhileCommand::DoCommand(std::vector<std::string> const&line)
{
    int temp_row_num = Parser::getIndex()+1;
    WhileLoop::whileLoop(line);
    return temp_row_num;
}

double WhileCommand::getVal(std::vector<std::string> const&line)
{

    double val = SymbolVar::getInstance()->getMapDouble().at(SymbolVar::getInstance()->getMapStr().at(line[1]));

    return val;
}

double WhileCommand::getVal(std::string const&word)
{
    double val = SymbolVar::getInstance()->getMapDouble().at(word);

    return val;
}

std::string WhileCommand::getStringVal(std::vector<std::string> const&line)
{
    std::string val = SymbolVar::getInstance()->getMapStr().at(line[3]);

    return val;
}

std::string WhileCommand::getStringVal(std::string const&word)
{
    std::string val = SymbolVar::getInstance()->getMapStr().at(word);

    return val;
}
