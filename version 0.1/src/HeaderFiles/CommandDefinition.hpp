#include "iostream"
#include <unistd.h>

#include "Command.hxx"
#include "WhileLoop.hpp"
#include "Parser.hpp"
#include "Client.hpp"
#include "SymbolVar.hpp"
#include "ShuntingYardToken.hpp"


void EqualMapCommand::updateFromDB(std::vector<std::string> &arr)
{
    convertFromChToNum(arr);
    
    strToInfix();

    checkMinus();
    
    double infix = ShuntingYardToken::shuntingYardF(WhileLoop::infix_str);

    Client::getInstance()->SendVal(arr,infix);
    
    WhileLoop::infix_str.clear();
}

void EqualMapCommand::convertFromChToNum(std::vector<std::string> &line)
{
    WhileLoop::copy_line = line;
    double d = 0.0;
    int dtoi = 0;
    std::string s;

    for (std::string::size_type i = 0; i < line.size(); i++) {
        for (std::string::size_type j = 0; j < SymbolVar::getInstance()->vec_all_vars.size(); j++) {
            if (line[i] == SymbolVar::getInstance()->vec_all_vars[j] && line[0] != SymbolVar::getInstance()->vec_all_vars[j]) {
                if (line[i] == "h0") {
                    d = SymbolVar::getInstance()->data_base.at(WhileLoop::copy_line[i]);
                }
                else {
                    d = SymbolVar::getInstance()->data_base.at(SymbolVar::getInstance()->base_map_DB.at(WhileLoop::copy_line[i]));
                }
                dtoi = d;
                s = std::to_string(dtoi);
                WhileLoop::copy_line[i] = s;
            }
        }
    }
}

void EqualMapCommand::strToInfix()
{
    std::string str_push_to_vec;

    for (std::string::size_type j = 0; j < WhileLoop::copy_line.size() - 2; j++) {
        str_push_to_vec += WhileLoop::copy_line[j + 2];
    }
    WhileLoop::infix_str = str_push_to_vec;
    str_push_to_vec.clear();
}

void EqualMapCommand::checkMinus()
{
    if (WhileLoop::infix_str[0] == '-' && WhileLoop::infix_str[1] == '-' ) {
        WhileLoop::infix_str.erase(WhileLoop::infix_str.begin()+1) ;
        WhileLoop::infix_str[0] = '+';
    }
}

int WhileCommand::skipRows(std::vector<std::vector<std::string>> const& arr,int index)
{ 
    int row_index = index+1;
    
    while (arr[row_index][0] != "}") {
        row_index++;    
    }
    std::cout << "\nHow meany rows to skip : " << row_index - index -1 << "\n";
    
    return row_index;  
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