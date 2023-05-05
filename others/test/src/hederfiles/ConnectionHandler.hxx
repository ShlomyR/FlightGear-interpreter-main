#pragma once

class ConnectionHandler
{
public:
    virtual ~ConnectionHandler() {}
    virtual void handleConnection() = 0;
};
