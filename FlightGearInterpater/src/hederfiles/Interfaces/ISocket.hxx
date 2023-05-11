#pragma once

class ISocket 
{
public:
    virtual ~ISocket() = default;
    virtual int createSocket() = 0;
};
