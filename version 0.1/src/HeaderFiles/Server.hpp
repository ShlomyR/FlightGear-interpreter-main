#pragma once

#include <string.h>
#include <vector>
#include <thread>

using namespace std;

#include "SymbolVar.hpp"



class Server
{
    public:
        static void endFG();
        std::string bind_arr[36];
        
        int connectServer(int port);
        static Server* getInstance();
    private:
        static Server* instance;
        std::string readData(std::string msg);
        std::vector<double> getValVector(std::string str);
        static void runServerDB();
        static void runFG();
        void makeBindArray();

        std::thread t1;
        std::thread t2;
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