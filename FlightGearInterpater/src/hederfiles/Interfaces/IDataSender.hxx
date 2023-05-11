#pragma once

#include <string>

class IDataSender 
{
public:
    virtual ~IDataSender() = default;
    virtual void sendData(std::string const&) = 0;
};