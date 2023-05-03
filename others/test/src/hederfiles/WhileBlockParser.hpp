#pragma once

#include <string>
#include <vector>

#include "BlockParser.hxx"

class WhileBlockParser : public BlockParser
{
public:
    void parse(std::vector<std::vector<std::string>> &lines) override;
    void reserve_block_type(std::vector<std::vector<std::string>> &lines, const std::string blockTyp) override;
};