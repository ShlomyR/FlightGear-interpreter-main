#include <string>
#include <vector>

#include "../hederfiles/IfBlockParser.hpp"

void IfBlockParser::parse(std::vector<std::vector<std::string>> &lines)
{
    reserve_block_type(lines, "if");
}
