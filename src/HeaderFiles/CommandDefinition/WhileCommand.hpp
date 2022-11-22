#include "iostream"

#include "../Command.hxx"
#include "../Variable.hpp"
#include "../SymbleVar.hpp"

int WhileCommand::skipRows(std::vector<std::string> &arr,int index)
{ 
    int row_index = index+1;
    
    while (arr[0] != "}") {
        row_index++;    
    }
    std::cout << "\nHow meany rows to skip : " << row_index - index -1 << "\n";
    
    return row_index;  
}

double WhileCommand::getVal(std::vector<std::vector<std::string>> &arr,int index)
{
    std::string path = Variable::getInstance()->base_map_DB.at(arr[index][1]);

    double val = SymbolVar::getInstance()->data_base.at(path);

    return val;
}