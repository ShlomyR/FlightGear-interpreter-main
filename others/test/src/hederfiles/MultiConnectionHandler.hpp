#pragma once

#include "../hederfiles/Interfaces/ConnectionHandler.hxx"

class MultiConnectionHandler : public ConnectionHandler 
{
public:
    void handleConnection() override;
};