#pragma once

#include <string>
#include <vector>

#include "Command.hxx"
#include "Tokenizer.hpp"
#include "ShuntingYard.hpp"
#include "Evaluator.hpp"

class AssignmentCommand : public Command
{
public:    
    void DoCommand(std::vector<std::string> const&) override;
private:
    void updateFromDB(std::vector<std::string> const&);
    void updateValuesFromDB(std::vector<std::string> const&);
    void incrementOrDecrement(const std::string&, int);
    double shuntingYard();
    std::string inputString();
private:
    std::string m_str;
    Tokenizer m_tokenizer;
    ShuntingYard m_shuntingYard;
    std::vector<std::string> m_copy_line;
};
