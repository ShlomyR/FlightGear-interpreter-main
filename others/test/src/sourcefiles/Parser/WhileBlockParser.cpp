#include <string>
#include <vector>

#include "../hederfiles/Parser/WhileBlockParser.hpp"

void WhileBlockParser::parse(std::vector<std::vector<std::string>> &lines)
{
    reserve_block_type(lines, "while");
}
