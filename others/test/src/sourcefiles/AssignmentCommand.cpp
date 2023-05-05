#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../hederfiles/AssignmentCommand.hpp"
#include "../hederfiles/MapException.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/Client.hpp"

void AssignmentCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line.size() == 3) {
        Client::getInstance()->sendData(line[0],line[2]);
    } else if (line[1] == "++") {
        incrementOrDecrementVariable(line[0], 1);
    } else if (line[1] == "--") {
        incrementOrDecrementVariable(line[0], -1);
    } else {
        updateVariableFromDB(line);
    }
}

void AssignmentCommand::incrementOrDecrementVariable(const std::string& variableName, int increment) {
    auto &varDoubleMap = SymbolVar::getInstance()->getMapDouble();
    try {
        if (varDoubleMap.count(variableName)) {
            int tempIncrement = varDoubleMap.at(variableName);
            varDoubleMap.at(variableName) = tempIncrement + increment;
        } else {
            throw MapException("Error: " + variableName + " not found in map_doubleDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
        }
    } catch (const MapException& me) {
        std::cout << me.what() << " at line " << me.where() << "\n";
    }
}

void AssignmentCommand::updateVariableFromDB(std::vector<std::string> const&line)
{
    updateValuesFromDB(line);
    double infix = shuntingYard();
    Client::getInstance()->sendData(line[0],infix);
}

void AssignmentCommand::updateValuesFromDB(std::vector<std::string> const&line)
{
    m_copy_line = line;
    const auto &varDoubleMap = SymbolVar::getInstance()->getMapDouble();
    const auto &varStringMap = SymbolVar::getInstance()->getMapStr();

    for (size_t i = 2; i < line.size(); i++) {
        try {       
            auto it = varStringMap.find(line[i]);
            if (it != varStringMap.end()) {
                auto jt = varDoubleMap.find(it->second);
                if (jt != varDoubleMap.end()) {
                    m_copy_line[i] = std::to_string(jt->second);
                } else {
                    throw MapException("Error: " + it->second + " not found in map_doubleDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
                }
            } else {
                throw MapException("Error: " + line[i] + " not found in map_strDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
            }
        } catch (const MapException& me) {
            std::cout << me.what() << " at line " << me.where() << "\n";
        }
    }
}

double AssignmentCommand::shuntingYard()
{
    auto tokens = m_tokenizer.tokenize(inputString());
    auto outputQueue = m_shuntingYard.shunt(tokens);
    Evaluator evaluator(outputQueue);
    auto result = evaluator.evaluate();
    std::cout << "\nResult: ";
    result->print(result->calc());
    return result->calc();
}

std::string AssignmentCommand::inputString()
{
    std::stringstream ss;
    for (size_t j = 0; j < m_copy_line.size() - 2; j++) {
        ss << m_copy_line[j + 2];
    }
    return ss.str();
}