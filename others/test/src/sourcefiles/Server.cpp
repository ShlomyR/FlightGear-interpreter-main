#include <sys/socket.h>
#include <iostream>
#include <istream>
#include <netinet/in.h>
#include <unistd.h>

#include <string.h>
#include <vector>
#include <memory>

#include "../hederfiles/FlightGear.hpp"
#include "../hederfiles/SymbolVar.hpp"
#include "../hederfiles/TcpServer.hpp"
#include "../hederfiles/Server.hpp"

Server* Server::getInstance()
{
    static Server instance;
    return &instance;
}

Server::~Server()
{
    if (t1.joinable()) {
        t1.detach();
    }
    if (t2.joinable()) {
        t2.detach();
    }   
}

int Server::connectServer(std::shared_ptr<ConnectionHandler> handler)
{
    makeBindArray();
    handler->handleConnection();
    return 0;
}

void Server::runServerDB() 
{
    char buffer[1024];
    bzero(buffer, 1024);
    std::string data, curr_data;
    std::vector<double> val_vector;

    while (true) {
        int i = 0;
        int val_read = read(TcpServer::getInstance()->getClientSocket(), buffer, 1024);
        
        data.append(buffer, val_read);
        
        curr_data = data.substr(0, data.find("\n"));
        data.erase(0, data.find("\n") + 1);
        val_vector = Server::getInstance()->getValVector(curr_data);
        
        for (double value : val_vector) {
            SymbolVar::getInstance()->creatDataBaseMap(Server::getInstance()->bind_arr[i%36],value);
            i++;
        }
    }
}

std::vector<double> Server::getValVector(std::string str) 
{
    char delimiter = ',';
    std::size_t pos = 0;
    std::string token;
    std::vector<double> vector;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        vector.push_back(stod(token));
        str.erase(0, pos + 1);
    }
    vector.push_back(stod(str));

    return vector;
}

bool Server::trySecondTime()
{
    std::cout << "Retrying connection in 10 seconds...\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));
    TcpServer::getInstance()->close();
    TcpServer::getInstance()->socket();
    return TcpServer::getInstance()->bind();
}

void Server::makeBindArray()
{
    bind_arr[airspeed] = "/instrumentation/airspeed-indicator/indicated-speed-kt";
    bind_arr[warp] = "/sim/time/warp";
    bind_arr[magnetos] = "/controls/switches/magnetos";
    bind_arr[heading] = "/instrumentation/heading-indicator/offset-deg";
    bind_arr[alt] = "/instrumentation/altimeter/indicated-altitude-ft";
    bind_arr[pressure] = "/instrumentation/altimeter/pressure-alt-ft";
    bind_arr[pitch] = "/instrumentation/attitude-indicator/indicated-pitch-deg";
    bind_arr[roll] = "/instrumentation/attitude-indicator/indicated-roll-deg";
    bind_arr[internal_pitch] = "/instrumentation/attitude-indicator/internal-pitch-deg";
    bind_arr[internal_roll] = "/instrumentation/attitude-indicator/internal-roll-deg";
    bind_arr[encoder_alt] = "/instrumentation/encoder/indicated-altitude-ft";
    bind_arr[encoder_pressure] = "/instrumentation/encoder/pressure-alt-ft";
    bind_arr[gps_alt] = "/instrumentation/gps/indicated-altitude-ft";
    bind_arr[gps_ground_speed] = "/instrumentation/gps/indicated-ground-speed-kt";
    bind_arr[gps_vertical_speed] = "/instrumentation/gps/indicated-vertical-speed";
    bind_arr[indicated_heading] = "/instrumentation/heading-indicator/indicated-heading-deg";
    bind_arr[compass] = "/instrumentation/magnetic-compass/indicated-heading-deg";
    bind_arr[slip_skid] = "/instrumentation/slip-skid-ball/indicated-slip-skid";
    bind_arr[turn_rate] = "/instrumentation/turn-indicator/indicated-turn-rate";
    bind_arr[indicated_speed] = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
    bind_arr[aileron] = "/controls/flight/aileron";
    bind_arr[elevator] = "/controls/flight/elevator";
    bind_arr[rudder] = "/controls/flight/rudder";
    bind_arr[flaps] = "/controls/flight/flaps";
    bind_arr[engine_throttle] = "/controls/engines/engine/throttle";
    bind_arr[curr_engine_throttle] = "/controls/engines/current-engine/throttle";
    bind_arr[master_avionics] = "/controls/switches/master-avionics";
    bind_arr[starter] = "/controls/switches/starter";
    bind_arr[auto_start] = "/engines/active-engine/auto-start";
    bind_arr[speed_brake] = "/controls/flight/speedbrake";
    bind_arr[brake_parking] = "/sim/model/c172p/brake-parking";
    bind_arr[engine_primer] = "/controls/engines/engine/primer";
    bind_arr[engine_mixture] = "/controls/engines/current-engine/mixture";
    bind_arr[master_bat] = "/controls/switches/master-bat";
    bind_arr[master_alt] = "/controls/switches/master-alt";
    bind_arr[engine_rpm] = "/engines/engine/rpm";
}
