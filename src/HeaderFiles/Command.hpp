#pragma once

#include <string>
#include <vector>

#include "Command.hxx"

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
    int DoCommand(std::vector<std::string> const&) override;
private:
    void updateFromDB(std::vector<std::string> const&);
    void convertFromChToNum(std::vector<std::string> const&);
};

class WhileCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
    static double getVal(std::vector<std::string> const&);
    static double getVal(std::string const&);
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

class BreakCommand : public Command
{
public:
    int DoCommand(std::vector<std::string> const&) override;
private:
    void breakFunc(std::vector<std::string> const&);
};