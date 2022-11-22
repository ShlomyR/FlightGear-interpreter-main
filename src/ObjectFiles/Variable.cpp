#include <iostream>

#include "../HeaderFiles/Variable.hpp"
#include "../HeaderFiles/SymbleVar.hpp"

Variable* Variable::instance = 0;
Variable* Variable::getInstance()
{
    if (instance == 0)
    {
        instance = new Variable();
    }
    return instance;
}

template<typename K, typename V>
void Variable::printMap(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}

void Variable::createVar(std::vector<std::string> var_arr)
{   
    if (var_arr[2] == "bind")
    {
        Variable::getInstance()->base_map_DB.insert({var_arr[0],var_arr[3]});
        Variable::getInstance()->vec_all_vars.push_back(Variable::getInstance()->base_map_DB.find(var_arr[0])->first);
    }
    
    else
    {
        getVarValue(var_arr);
    }   
}

void Variable::getVarValue(std::vector<std::string> var_arr)
{          
    SymbolVar::getInstance()->data_base[var_arr[0]];
    SymbolVar::getInstance()->data_base.at(var_arr[0]) = SymbolVar::getInstance()->data_base.at(Variable::getInstance()->base_map_DB.at(var_arr[2]));
    Variable::getInstance()->vec_all_vars.insert(Variable::getInstance()->vec_all_vars.begin(), SymbolVar::getInstance()->data_base.find(var_arr[0])->first);
}