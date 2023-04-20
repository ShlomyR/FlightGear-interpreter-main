#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "../hederfiles/ConditionChecker.hpp"

class SymbolVar
{
public:
    static SymbolVar* getInstance();
public:
    void createVar(std::vector<std::string> const&);
    std::unordered_map<std::string,double> creatDataBaseMap(std::string key,double const&);
    std::unordered_map<std::string,std::string> creatDataBaseMap(std::string key,std::string const&);
    std::unordered_map<std::string,std::string>& getMapStr();
    std::unordered_map<std::string,double>& getMapDouble();
    std::vector<std::string>& getVecAllVars();
private:
    SymbolVar() {}
    SymbolVar(const SymbolVar&) = delete;
    SymbolVar& operator=(const SymbolVar&) = delete;

    void assignVar(std::vector<std::string> const &);
    void checkDup(std::string);
    void getVarValue(std::vector<std::string> const&);
    
    template<typename K, typename V>
    void printMap(std::unordered_map<K, V> const& m);
    template<typename K>
    void printMap(std::vector<K> const &m);
private:
    std::unordered_map<std::string,std::string> map_strDB;
    std::unordered_map<std::string,double> map_doubleDB;
    std::vector<std::string>  vec_all_vars;
    ConditionChecker m_conditionCheck;
};
