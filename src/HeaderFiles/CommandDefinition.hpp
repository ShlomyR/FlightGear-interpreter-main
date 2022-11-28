#include "iostream"
#include <unistd.h>

#include "Command.hxx"
#include "WhileLoop.hpp"
#include "Parser.hpp"
#include "Client.hpp"
#include "SymbolVar.hpp"
#include "ShuntingYardToken.hpp"


void EqualMapCommand::updateFromDB(std::vector<std::string> &line)
{
    convertFromChToNum(line);
    
    ShuntingYardToken::strToInfix();

    ShuntingYardToken::checkMinus();
    
    double infix = ShuntingYardToken::shuntingYardF(ShuntingYardToken::getInfix());

    Client::getInstance()->SendVal(line,infix);
    
    ShuntingYardToken::getInfix().clear();
}

void EqualMapCommand::convertFromChToNum(std::vector<std::string> &line)
{
    ShuntingYardToken::setCopy(line);
    double d = 0.0;
    int dtoi = 0;
    std::string s;

    for (std::string::size_type i = 0; i < line.size(); i++) {
        for (std::string::size_type j = 0; j < SymbolVar::getInstance()->vec_all_vars.size(); j++) {
            if (line[i] == SymbolVar::getInstance()->vec_all_vars[j] && line[0] != SymbolVar::getInstance()->vec_all_vars[j]) {
                if (line[i] == "h0") {
                    d = SymbolVar::getInstance()->data_base.at(ShuntingYardToken::getCopy()[i]);
                }
                else {
                    d = SymbolVar::getInstance()->data_base.at(SymbolVar::getInstance()->base_map_DB.at(ShuntingYardToken::getCopy()[i]));
                }
                dtoi = d;
                s = std::to_string(dtoi);
                ShuntingYardToken::setCopy(s,i);
            }
        }
    }
}

double WhileCommand::getVal(std::vector<std::string> const& line)
{
    std::string path = SymbolVar::getInstance()->base_map_DB.at(line[1]);

    double val = SymbolVar::getInstance()->data_base.at(path);

    return val;
}

void SleepCommand::sleepFunc(std::string val)
{
    std::cout << "\nSleeping for " << val << " seconds" << "\n"; 
    sleep(stoi(val));
}

void PrintCommand::printFunc(std::string val)
{
    std::string val_name = val;

    for (std::string::size_type i = 0; i < SymbolVar::getInstance()->vec_all_vars.size(); i++) {
        if (val == SymbolVar::getInstance()->vec_all_vars[i]) {
            double val_d = SymbolVar::getInstance()->data_base.at(SymbolVar::getInstance()->base_map_DB.at(val));
            std::cout << val_name << ": " << val_d << "\n";
        }
    }
    if (val[0] == '"') {    
        std::cout << "\n" << val << "\n";   
    }
}