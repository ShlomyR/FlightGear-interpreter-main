#pragma once

#include "ConnectionHandler.hxx"

#include <string>
#include <vector>
#include <thread>
#include <memory>

class Server
{
public:
    ~Server();
    static Server* getInstance();
    int connectServer(std::shared_ptr<ConnectionHandler> );
    static void runServerDB();
    bool trySecondTime();
    std::thread &getFlightGearThread();
    std::thread &getServerDataBaseThread();
private:
    Server() = default;
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;

    std::string readData(std::string const);
    std::vector<double> getValVector(std::string);
    void makeBindArray();
private:
    std::thread flightGearThread;
    std::thread serverDatabaseThread;
    std::string bind_arr[36];
};

enum vars {
    airspeed = 0,
    warp,
    magnetos,
    heading,
    alt,
    pressure,
    pitch,
    roll,
    internal_pitch,
    internal_roll,
    encoder_alt,
    encoder_pressure,
    gps_alt,
    gps_ground_speed,
    gps_vertical_speed,
    indicated_heading,
    compass,
    slip_skid,
    turn_rate,
    indicated_speed,
    aileron,
    elevator,
    rudder,
    flaps,
    engine_throttle,
    curr_engine_throttle,
    master_avionics,
    starter,
    auto_start,
    speed_brake,
    brake_parking,
    engine_primer,
    engine_mixture,
    master_bat,
    master_alt,
    engine_rpm,
    brakes
};
