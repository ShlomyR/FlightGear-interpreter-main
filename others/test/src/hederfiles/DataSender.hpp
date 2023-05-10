#pragma once

#include <string>

#include "../hederfiles/Interfaces/IDataSender.hxx"

class DataSender : public IDataSender 
{
public:
    void sendData(std::string const &) override;
};