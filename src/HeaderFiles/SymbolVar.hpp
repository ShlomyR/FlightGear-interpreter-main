#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class SymbolVar
{
public:
    std::unordered_map<std::string,double> data_base;
    std::unordered_map<std::string,std::string> base_map_DB;
    std::vector<std::string>  vec_all_vars;
public:
    std::unordered_map<std::string,double> creatDataBaseMap(std::string key,double const& val);
    static SymbolVar* getInstance();
    void createVar(std::vector<std::string> const);
private:
    SymbolVar();
    static SymbolVar* instance;
private:
    void getVarValue(std::vector<std::string> const);
    template<typename K, typename V>
    void printMap(std::unordered_map<K, V> const& m);
};