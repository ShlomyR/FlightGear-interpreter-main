#pragma once

#include <string>
#include <vector>

#include "../hederfiles/ShuntingYard/ShuntingYard.hpp"
#include "../hederfiles/ShuntingYard/Evaluator.hpp"
#include "../hederfiles/Interfaces/Command.hxx"
#include "../hederfiles/Token/Tokenizer.hpp"

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
