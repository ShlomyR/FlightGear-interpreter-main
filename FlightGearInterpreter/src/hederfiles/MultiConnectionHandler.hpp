#pragma once

#include "ConnectionHandler.hxx"

class MultiConnectionHandler : public ConnectionHandler 
{
public:
    void handleConnection() override;
};