#include <string>
#include <vector>

#include "../hederfiles/Commands/IfCommand.hpp"
#include "../hederfiles/ifCondition.hpp"
#include "../hederfiles/Parser/Parse.hpp"

void IfCommand::DoCommand(std::vector<std::string> const&line)
{
    ifCondition::ifCon(line);
}