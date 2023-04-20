#include <string>
#include <vector>

#include "../hederfiles/VerCommand.hpp"
#include "../hederfiles/SymbolVar.hpp"

int VerCommand::DoCommand(std::vector<std::string> const&line)
{
    SymbolVar::getInstance()->createVar(line);
    
    return 0;
}