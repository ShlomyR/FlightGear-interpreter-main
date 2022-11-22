#include "iostream"
#include <unistd.h>

#include "Command.hxx"
#include "WhileLoop.hpp"
#include "Parser.hpp"
#include "Client.hpp"
#include "Variable.hpp"
#include "SymbleVar.hpp"
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
        for (std::string::size_type j = 0; j < Variable::getInstance()->vec_all_vars.size(); j++) {
            if (line[i] == Variable::getInstance()->vec_all_vars[j] && line[0] != Variable::getInstance()->vec_all_vars[j]) {
                if (line[i] == "h0") {
                    d = SymbolVar::getInstance()->data_base.at(WhileLoop::copy_line[i]);
                }
                else {
                    d = SymbolVar::getInstance()->data_base.at(Variable::getInstance()->base_map_DB.at(WhileLoop::copy_line[i]));
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


void PrintCommand::printFunc(std::string val)
{
    std::string val_name = val;

    for (std::string::size_type i = 0; i < Variable::getInstance()->vec_all_vars.size(); i++) {
        if (val == Variable::getInstance()->vec_all_vars[i]) {
            double val_d = SymbolVar::getInstance()->data_base.at(Variable::getInstance()->base_map_DB.at(val));
            std::cout << val_name << ": " << val_d << "\n";
        }
    }
    if (val[0] == '"') {    
        std::cout << "\n" << val << "\n";   
    }

}


void SleepCommand::sleepFunc(std::string val)
{
    std::cout << "\nSleeping for " << val << " seconds" << "\n"; 
    sleep(stoi(val));
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

double WhileCommand::getVal(std::vector<std::vector<std::string>> const& arr,int i)
{
    std::string path = Variable::getInstance()->base_map_DB.at(arr[i][1]);

    double val = SymbolVar::getInstance()->data_base.at(path);

    return val;
}