#include <iostream>

#include "../HeaderFiles/SymbleVar.hpp"


SymbolVar* SymbolVar::instance = 0;
SymbolVar* SymbolVar::getInstance()
{
    if (instance == 0)
    {
        instance = new SymbolVar();
    }
    return instance;
}

template<typename Ks, typename Vs>
void SymbolVar::printMapDB(std::unordered_map<Ks, Vs> const &m)
{
    for (auto const &pair: m) 
    {
        std::cout << "{" << pair.first << " : " << pair.second << "}\n";
    }
    
}

std::unordered_map<std::string,double> SymbolVar::creatDataBaseMap(std::string key,double val)
{    
    SymbolVar::getInstance()->data_base[key] = val;

    return SymbolVar::getInstance()->data_base;    
}
