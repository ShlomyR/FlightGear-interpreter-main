#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class SymbolVar
{
    public:
        static SymbolVar* getInstance();
        std::unordered_map<std::string,double> data_base;
        std::unordered_map<std::string,double> creatDataBaseMap(std::string key,double val);
    private:
        static SymbolVar* instance;
        template<typename K, typename V>
        void printMapDB(std::unordered_map<K, V> const &m);
};