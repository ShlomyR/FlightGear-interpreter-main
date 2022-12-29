#include "../HeaderFiles/CheckCondition.hpp"
#include "../HeaderFiles/Command.hpp"

#include <string>
#include <vector>
#include <iostream>

bool CheckCondition(std::vector<std::string> const&line)
{
    double val_from_DB = 0.0;
    double val_from_DB_B = 0.0;
    //val_from_DB = WhileCommand::getVal(line);
    if (line[2] == "<") {
        std::cout << "< was called." << "\n";
        return (val_from_DB = WhileCommand::getVal(line)) < stoi(line[3]);
    } else if (line[2] == ">") {
        std::cout << "> was called." << "\n";
        return (val_from_DB = WhileCommand::getVal(line)) > stoi(line[3]);
    } else if (line[2] == "==") {
        std::cout << "== was called." << "\n";
        return (val_from_DB = WhileCommand::getVal(line)) == stoi(line[3]) || (val_from_DB = WhileCommand::getVal(line[1])) == (val_from_DB_B = WhileCommand::getVal(line[3]));
    } else if (line[2] == "<=") {
        std::cout << "<= was called." << "\n";
        return (val_from_DB = WhileCommand::getVal(line)) <= stoi(line[3]);
    } else if (line[2] == ">=") {
        std::cout << ">= was called." << "\n";
        return (val_from_DB = WhileCommand::getVal(line)) >= stoi(line[3]);
    } else if (line[2] == "!=") {
        std::cout << "!= was called." << "\n";
        return (val_from_DB = WhileCommand::getVal(line)) != stoi(line[3]);
    } else {
        throw std::runtime_error("This is unknown condition");
    }
}