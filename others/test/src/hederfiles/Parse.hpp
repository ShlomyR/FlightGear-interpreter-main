#pragma once

#include <vector>
#include <memory>

#include "CommandFactory.hpp"
#include "LinesPointer.hpp"
#include "Command.hxx"
#include "Parser.hxx"

class Parse : public Parser
{
public:
    Parse() {}
    void parse(std::vector<std::vector<std::string>> &lines) override;
public:
    // static std::string::size_type getIndex();
    // static void incrementIndex();
    // static void setIndex(int i);
    // void resetIndex();
private:
    Parse(const Parse&) = delete;
    Parse& operator=(const Parse&) = delete;

private:
    CommandFactory m_command_factory;
    LinesPointer m_lines_pointer;
    static size_t m_index;
};
