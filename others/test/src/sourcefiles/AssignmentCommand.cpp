#include <iostream>
#include <string>
#include <vector>

#include "../hederfiles/AssignmentCommand.hpp"
#include "../hederfiles/MapException.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/Client.hpp"

void AssignmentCommand::DoCommand(std::vector<std::string> const&line)
{
    if (line.size() == 3) {
        Client::getInstance()->sendData(line,line[2]);
    } else if (line[1] == "++") {
        incrementOrDecrement(line[0], 1);
    } else if (line[1] == "--") {
        incrementOrDecrement(line[0], -1);
    } else {
        updateFromDB(line);
    }
}

void AssignmentCommand::incrementOrDecrement(const std::string& varName, int increment) {
    try {
        if (SymbolVar::getInstance()->getMapDouble().count(varName)) {
            int tempIncrement = SymbolVar::getInstance()->getMapDouble().at(varName);
            SymbolVar::getInstance()->getMapDouble().at(varName) = tempIncrement + increment;
        } else {
            throw MapException("Error: " + varName + " not found in map_doubleDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
        }
    } catch (const MapException& me) {
        std::cout << me.what() << " at line " << me.where() << "\n";
    }
}

void AssignmentCommand::updateFromDB(std::vector<std::string> const&line)
{
    updateValuesFromDB(line);
    double infix = shuntingYard();
    Client::getInstance()->sendData(line,infix);
}

void AssignmentCommand::updateValuesFromDB(std::vector<std::string> const&line)
{
    m_copy_line = line;
    double d = 0.0;

    for (size_t i = 0; i < line.size(); i++) {
        for (size_t j = 0; j < SymbolVar::getInstance()->getVecAllVars().size(); j++) {
            if (line[i] == SymbolVar::getInstance()->getVecAllVars()[j] && line[0] != SymbolVar::getInstance()->getVecAllVars()[j]) {
                try {
                    if (SymbolVar::getInstance()->getMapDouble().count(SymbolVar::getInstance()->getMapStr().at(m_copy_line[i]))) {
                        d = SymbolVar::getInstance()->getMapDouble().at(SymbolVar::getInstance()->getMapStr().at(m_copy_line[i]));
                    } else {
                        throw MapException("Error: " + m_copy_line[i] + " not found in map_doubleDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
                    }
                } catch (const MapException& me) {
                    std::cout << me.what() << " at line " << me.where() << "\n";
                }
                m_copy_line[i] = std::to_string(d);
            }
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
    m_str = "";
    for (size_t j = 0; j < m_copy_line.size() - 2; j++) {
        m_str += m_copy_line[j + 2];
    }
    return m_str;
}