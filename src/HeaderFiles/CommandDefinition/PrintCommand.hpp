#include "iostream"

#include "../Command.hxx"
#include "../Variable.hpp"
#include "../SymbleVar.hpp"

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