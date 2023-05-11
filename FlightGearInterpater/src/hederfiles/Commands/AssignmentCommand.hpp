#pragma once

#include "ShuntingYard.hpp"
#include "Evaluator.hpp"
#include "Tokenizer.hpp"
#include "Command.hxx"

#include <string>
#include <vector>

class AssignmentCommand : public Command
{
public:    
    void DoCommand(std::vector<std::string> const&) override;
private:
    void updateVariableFromDB(std::vector<std::string> const&);
    void updateValuesFromDB(std::vector<std::string> const&);
    void incrementOrDecrementVariable(const std::string&, int);
    double shuntingYard();
    std::string inputString();
private:
    Tokenizer m_tokenizer;
    ShuntingYard m_shuntingYard;

    std::string m_str;
    std::vector<std::string> m_copy_line;
};
