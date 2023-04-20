#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class SymbolVar
{
    public:
        static SymbolVar* getInstance();
    public:
        std::unordered_map<std::string,double> data_base;
        std::unordered_map<std::string,std::string> base_map_DB;
        std::vector<std::string>  vec_all_vars;
    public:
        std::unordered_map<std::string,double> creatDataBaseMap(std::string key,double const& val);
        void createVar(std::vector<std::string> var_arr);
    private:
        SymbolVar();
        static SymbolVar* instance;
    private:
        void getVarValue(std::vector<std::string> var_arr);
        template<typename K, typename V>
        void printMap(std::unordered_map<K, V> const& m);
};