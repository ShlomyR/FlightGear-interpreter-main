#pragma once

#include <string>
#include <vector>

#include "Parser.hxx"

class BlockParser : public Parser
{
public:
    ~BlockParser() = default;
    virtual void reserve_block_type(std::vector<std::vector<std::string>> &lines, const std::string blockTyp) = 0;
};