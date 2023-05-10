#pragma once

class ConnectionHandler
{
public:
    virtual ~ConnectionHandler() = default;
    virtual void handleConnection() = 0;
};
