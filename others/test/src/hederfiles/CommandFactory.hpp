#pragma once

#include <unordered_map>
#include <memory>
#include <string>
#include <functional>

#include "Command.hxx"

#include "OpenServerCommand.hpp"
#include "ConnectCommand.hpp"
#include "VerCommand.hpp"
#include "IfCommand.hpp"
#include "WhileCommand.hpp"
#include "SleepCommand.hpp"
#include "PrintCommand.hpp"
#include "BreakCommand.hpp"
#include "AssignmentCommand.hpp"

class CommandFactory {
public:
    CommandFactory();
    std::shared_ptr<Command> createCommand(const std::vector<std::string>& tokens) const;
private:
    std::unordered_map<std::string, std::function<std::shared_ptr<Command>()>> m_command_creators;
};

