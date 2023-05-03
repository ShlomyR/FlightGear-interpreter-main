#pragma once

#include <string>

#include "IDataSender.hxx"

class DataSender : public IDataSender {
public:
    void sendData(std::string const& msg) override;
};