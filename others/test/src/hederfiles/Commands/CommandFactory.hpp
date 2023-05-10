#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include <functional>

#include "../hederfiles/Interfaces/Command.hxx"

#include "../hederfiles/Commands/OpenServerCommand.hpp"
#include "../hederfiles/Commands/ConnectCommand.hpp"
#include "../hederfiles/Commands/VerCommand.hpp"
#include "../hederfiles/Commands/IfCommand.hpp"
#include "../hederfiles/Commands/WhileCommand.hpp"
#include "../hederfiles/Commands/SleepCommand.hpp"
#include "../hederfiles/Commands/PrintCommand.hpp"
#include "../hederfiles/Commands/BreakCommand.hpp"
#include "../hederfiles/Commands/AssignmentCommand.hpp"

class CommandFactory {
public:
    CommandFactory();
    std::shared_ptr<Command> createCommand(const std::vector<std::string> &) const;
private:
    std::unordered_map<std::string, std::function<std::shared_ptr<Command>()>> m_command_creators;
};

