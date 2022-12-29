#include "iostream"
#include <unistd.h>

#include "../HeaderFiles/Command.hpp"
#include "../HeaderFiles/Client.hpp"
#include "../HeaderFiles/SymbolVar.hpp"
#include "../HeaderFiles/ShuntingYardToken.hpp"
#include "../HeaderFiles/Parser.hpp"


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
                str = std::to_string(dtoi);
                ShuntingYardToken::setCopy(str,i);
            }
        }
    }
}

double WhileCommand::getVal(std::vector<std::string> const&line)
{
    std::string path = SymbolVar::getInstance()->base_map_DB.at(line[1]);

    double val = SymbolVar::getInstance()->data_base.at(path);

    return val;
}

double WhileCommand::getVal(std::string const&line)
{
    std::string path = SymbolVar::getInstance()->base_map_DB.at(line);

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

void BreakCommand::breakFunc(std::vector<std::string> const&line)
{
    std::cout << "\nBreakCommand was called: " << line[0] << "\n"; 
    Parser::incrementIndex();
    Parser::incrementIndex();
    
}