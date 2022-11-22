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
        void strToInfix();
        void checkMinus();
};

class WhileCommand : public Command
{
    public:
        int DoCommand(std::vector<std::string> &line) override;
        static double getVal(std::vector<std::vector<std::string>> const&arr,int index);
    private:
        int skipRows(std::vector<std::vector<std::string>> const&arr,int index);
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