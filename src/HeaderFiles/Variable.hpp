#pragma once

#include <unordered_map>

#include "Command.hpp"
    
class Variable
{
    public:
        std::unordered_map<std::string,std::string> base_map_DB;
        std::vector<std::string>  vec_all_vars;
        static Variable* getInstance();
        void createVar(std::vector<std::string> var_arr);
    private:
        static Variable* instance;
        void getVarValue(std::vector<std::string> var_arr);
        template<typename K, typename V>
        void printMap(std::unordered_map<K, V> const &m);
};





