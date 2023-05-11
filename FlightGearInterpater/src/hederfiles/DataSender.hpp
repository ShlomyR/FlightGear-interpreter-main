#pragma once

#include "IDataSender.hxx"

#include <string>

class DataSender : public IDataSender 
{
public:
    void sendData(std::string const &) override;
};
