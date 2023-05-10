#include <string>
#include <vector>

#include "../hederfiles/Commands/VerCommand.hpp"
#include "../hederfiles/SymbolVar.hpp"

void VerCommand::DoCommand(std::vector<std::string> const&line)
{
    SymbolVar::getInstance()->createVar(line);
}