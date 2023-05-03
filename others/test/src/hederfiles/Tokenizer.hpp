#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Token.hxx"

class Tokenizer
{
public:
    std::vector<std::shared_ptr<Token>> tokenize(const std::string& input) const;
};
