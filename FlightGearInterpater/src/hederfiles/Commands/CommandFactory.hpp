#pragma once

#include "AssignmentCommand.hpp"
#include "OpenServerCommand.hpp"
#include "ConnectCommand.hpp"
#include "WhileCommand.hpp"
#include "SleepCommand.hpp"
#include "PrintCommand.hpp"
#include "BreakCommand.hpp"
#include "VerCommand.hpp"
#include "IfCommand.hpp"
#include "Command.hxx"

#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

class CommandFactory {
public:
    CommandFactory();
    std::shared_ptr<Command> createCommand(const std::vector<std::string> &) const;
private:
    std::unordered_map<std::string, std::function<std::shared_ptr<Command>()>> m_command_creators;
};

