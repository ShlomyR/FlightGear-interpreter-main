#include <string>
#include <vector>

#include "../hederfiles/ifCondition.hpp"
#include "../hederfiles/IfCommand.hpp"
#include "../hederfiles/Parse.hpp"

void IfCommand::DoCommand(std::vector<std::string> const&line)
{
    ifCondition::ifCon(line);
}