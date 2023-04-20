#include <iostream>
#include <unistd.h>

#include "../HeaderFiles/SymbolVar.hpp"

SymbolVar* SymbolVar::instance = 0;
SymbolVar* SymbolVar::getInstance()
{
    if (instance == 0) {
        instance = new SymbolVar();
    }
    return instance;
}

SymbolVar::SymbolVar(){}

std::unordered_map<std::string,double> SymbolVar::creatDataBaseMap(std::string key,double const& val)
{    
    SymbolVar::getInstance()->data_base[key] = val;

    return SymbolVar::getInstance()->data_base;    
}

void SymbolVar::createVar(std::vector<std::string> const var_arr)
{   
    if (var_arr[2] == "bind") {
        SymbolVar::getInstance()->base_map_DB.insert({var_arr[0],var_arr[3]});
        SymbolVar::getInstance()->vec_all_vars.push_back(SymbolVar::getInstance()->base_map_DB.find(var_arr[0])->first);
    }
    
    else {
        getVarValue(var_arr);
    }   
}

void SymbolVar::getVarValue(std::vector<std::string> const var_arr)
{          
    SymbolVar::getInstance()->data_base[var_arr[0]];
    SymbolVar::getInstance()->data_base.at(var_arr[0]) = SymbolVar::getInstance()->data_base.at(SymbolVar::getInstance()->base_map_DB.at(var_arr[2]));
    SymbolVar::getInstance()->vec_all_vars.insert(SymbolVar::getInstance()->vec_all_vars.begin(), SymbolVar::getInstance()->data_base.find(var_arr[0])->first);
}

template<typename K, typename V>
void SymbolVar::printMap(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}