#pragma once

#include "Command.hpp"

class OpenServerCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> &line) override;
};

class ConnectCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> &line) override; 
};

class VerCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> &line) override;
};

class EqualMapCommand : public Command
{
    public:    
        int DoCommand(std::vector<std::string> &line) override;
    private:
        void updateFromDB(std::vector<std::string> &arr);
        void convertFromChToNum(std::vector<std::string> &arr);
};

class WhileCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> &line) override;
        static double getVal(std::vector<std::string> const& line);
};

class SleepCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> &line) override;
    private:
        void sleepFunc(std::string val);
};

class PrintCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> &line) override;
    private:
        void printFunc(std::string val);
};