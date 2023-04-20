#include <string>
#include <vector>

#include "../hederfiles/ifCondition.hpp"
#include "../hederfiles/IfCommand.hpp"
#include "../hederfiles/Parser.hpp"

int IfCommand::DoCommand(std::vector<std::string> const&line)
{
    int temp_row_num = Parser::getIndex()+1;
    ifCondition::ifCon(line);
    return temp_row_num;
}