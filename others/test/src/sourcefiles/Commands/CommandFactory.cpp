#include "../hederfiles/Commands/CommandFactory.hpp"

CommandFactory::CommandFactory()
{
    m_command_creators["openDataServer"] = []() { return std::make_shared<OpenServerCommand>(); };
    m_command_creators["connect"] = []() { return std::make_shared<ConnectCommand>(); };
    m_command_creators["var"] = []() { return std::make_shared<VerCommand>(); };
    m_command_creators["="] = []() { return std::make_shared<AssignmentCommand>(); };
    m_command_creators["++"] = []() { return std::make_shared<AssignmentCommand>(); };
    m_command_creators["if"] = []() { return std::make_shared<IfCommand>(); };
    m_command_creators["while"] = []() { return std::make_shared<WhileCommand>(); };
    m_command_creators["sleep"] = []() { return std::make_shared<SleepCommand>(); };
    m_command_creators["print"] = []() { return std::make_shared<PrintCommand>(); };
    m_command_creators["break"] = []() { return std::make_shared<BreakCommand>(); };
}

std::shared_ptr<Command> CommandFactory::createCommand(const std::vector<std::string>& tokens) const
{
    if (tokens.empty()) {
        return nullptr;
    }

    auto creator_func = m_command_creators.find(tokens[0]);
    if (tokens.size() > 1 && creator_func == m_command_creators.end()) {
        creator_func = m_command_creators.find(tokens[1]);
    }
    
    if (creator_func == m_command_creators.end()) {
        return nullptr;
    }

    return creator_func->second();
}