#pragma once

#include <string>
#include <vector>

#include "Command.hpp"

class OpenServerCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> const&) override;
};

class ConnectCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> const&) override; 
};

class VerCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> const&) override;
};

class EqualMapCommand : public Command
{
    public:    
        int DoCommand(std::vector<std::string> const&line) override;
    private:
        void updateFromDB(std::vector<std::string> const&line);
        void convertFromChToNum(std::vector<std::string> const&line);
};

class WhileCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> const&line) override;
        static double getVal(std::vector<std::string> const&line);
};

class SleepCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> const&) override;
    private:
        void sleepFunc(std::string);
};

class PrintCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> const&) override;
    private:
        void printFunc(std::string);
};