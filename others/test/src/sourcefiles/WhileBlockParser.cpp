#include <string>
#include <vector>

#include "../hederfiles/WhileBlockParser.hpp"
#include "../hederfiles/Lexer.hpp"

void WhileBlockParser::parse(std::vector<std::vector<std::string>> &lines)
{
    reserve_block_type(lines, "while");
}

void WhileBlockParser::reserve_block_type(std::vector<std::vector<std::string>> &lines, const std::string blockTyp)
{
    size_t i = 0;
    std::vector<std::vector<std::string>> vvc = {};
    while (!lines[i].empty() && i < lines.size()) {
        if (lines[i][0] != blockTyp) {
            lines.erase(lines.begin() + i);
        } else {
            lines.erase(lines.begin() + i);
            lines.erase(lines.begin() + i);
            while (lines[i][0] != "}")  {
                vvc.push_back(lines[i]);
                ++i;
            }
            Lexer::get_while_blocks().push_back(vvc);
            vvc.clear();
            lines.erase(lines.begin() + i);
        }
    }
}