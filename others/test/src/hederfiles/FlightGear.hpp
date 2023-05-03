#pragma once

class FlightGear
{
public:
    static FlightGear *getInstance();
    void open();
    void close();
    bool isOpen();
private:
    FlightGear();
    bool m_isOpen;
};
