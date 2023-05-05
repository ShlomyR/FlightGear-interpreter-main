#include <string>
#include <vector>

#include "../hederfiles/LinesBlockParser.hpp"
#include "../hederfiles/Lexer.hpp"

void LinesBlockParser::parse(std::vector<std::vector<std::string>> &lines)
{
    Lexer::get_lines_blocks().push_back(lines);
}
