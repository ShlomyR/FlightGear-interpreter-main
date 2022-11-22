#include "../Command.hxx"
#include "../WhileLoop.hpp"
#include "../Parser.hpp"
#include "../Client.hpp"
#include "../Variable.hpp"
#include "../SymbleVar.hpp"
#include "../ShuntingYardToken.hpp"


void EqualMapCommand::updateFromDB(std::vector<std::vector<std::string>> &arr)
{
    convertFromChToNum(arr);
    
    strToInfix(Parser::index);

    checkMinus();
    
    double infix = ShuntingYardToken::shuntingYardF(WhileLoop::infix_str);

    Client::getInstance()->SendVal(arr,infix);
    
    WhileLoop::infix_str.clear();
}

void EqualMapCommand::convertFromChToNum(std::vector<std::vector<std::string>> &arr)
{
    WhileLoop::copy_arr = arr;
    double d;
    int dtoi;
    std::string s;

    for (std::string::size_type i = 0; i < arr[Parser::index].size(); i++) {
        for (std::string::size_type j = 0; j < Variable::getInstance()->vec_all_vars.size(); j++) {
            if (arr[Parser::index][i] == Variable::getInstance()->vec_all_vars[j] && arr[Parser::index][0] != Variable::getInstance()->vec_all_vars[j]) {
                if (arr[Parser::index][i] == "h0") {
                    d = SymbolVar::getInstance()->data_base.at(WhileLoop::copy_arr[Parser::index][i]);
                }
                else {
                    d = SymbolVar::getInstance()->data_base.at(Variable::getInstance()->base_map_DB.at(WhileLoop::copy_arr[Parser::index][i]));
                }
                dtoi = d;
                s = std::to_string(dtoi);
                WhileLoop::copy_arr[Parser::index][i] = s;
            }
        }
    }
}

void EqualMapCommand::strToInfix(std::string::size_type i)
{
    std::string str_push_to_vec;

    for (std::string::size_type j = 0; j < WhileLoop::copy_arr[i].size() - 2; j++) {
        str_push_to_vec += WhileLoop::copy_arr[i][j + 2];
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