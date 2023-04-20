#include <string>
#include <vector>

#include "../hederfiles/ShuntingYardToken.hpp"
#include "../hederfiles/EqualMapCommand.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/Client.hpp"

int EqualMapCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line.size() == 3) {
        Client::getInstance()->SendVal(line,line[2]);
    } else if (line[1] == "++") {
        int tempIncrement = SymbolVar::getInstance()->getMapDouble().at(line[0]);
        SymbolVar::getInstance()->getMapDouble().at(line[0]) = ++tempIncrement;
    } else if (line[1] == "--") {
        int tempIncrement = SymbolVar::getInstance()->getMapDouble().at(line[0]);
        SymbolVar::getInstance()->getMapDouble().at(line[0]) = --tempIncrement;
    } else {
        updateFromDB(line);
    }

    return 0;
}

void EqualMapCommand::updateFromDB(std::vector<std::string> const&line)
{
    convertFromChToNum(line);
    
    ShuntingYardToken::strToInfix();

    ShuntingYardToken::checkMinus();
    
    double infix = ShuntingYardToken::shuntingYardF(ShuntingYardToken::getInfix());

    Client::getInstance()->SendVal(line,infix);
    
    ShuntingYardToken::getInfix().clear();
}

void EqualMapCommand::convertFromChToNum(std::vector<std::string> const&line)
{
    ShuntingYardToken::setCopy(line);
    double d = 0.0;
    int dtoi = 0;
    std::string str;

    for (size_t i = 0; i < line.size(); i++) {
        for (size_t j = 0; j < SymbolVar::getInstance()->getVecAllVars().size(); j++) {
            if (line[i] == SymbolVar::getInstance()->getVecAllVars()[j] && line[0] != SymbolVar::getInstance()->getVecAllVars()[j]) {
                d = SymbolVar::getInstance()->getMapDouble().at(SymbolVar::getInstance()->getMapStr().at(ShuntingYardToken::getCopy()[i]));
                dtoi = d;
                str = std::to_string(dtoi);
                ShuntingYardToken::setCopy(str,i);
            }
        }
    }
}