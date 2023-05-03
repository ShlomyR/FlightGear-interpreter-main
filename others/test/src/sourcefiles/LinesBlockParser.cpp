#include <string>
#include <vector>

#include "../hederfiles/LinesBlockParser.hpp"

void LinesBlockParser::parse(std::vector<std::vector<std::string>> &)
{
    return ;
}

void LinesBlockParser::reserve_block_type(std::vector<std::vector<std::string>> &lines, const std::string blockTyp)
{
    size_t i = 0;
    while (!lines[i].empty() && i < lines.size()) {
        if (lines[i][0] != blockTyp) {
            lines.erase(lines.begin() + i);
        } else {
            i += 2;
            while (lines[i][0] != "}")  {
                ++i;
            }
            ++i;
        }
    }
}