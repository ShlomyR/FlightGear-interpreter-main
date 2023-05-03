#pragma once

#include <string>

class IDataSender {
public:
    virtual ~IDataSender() {}
    virtual void sendData(std::string const& msg) = 0;
};