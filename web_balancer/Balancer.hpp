#ifndef BALANCER_HPP
#define BALANCER_HPP

#include "ServersPool.hpp"
#include <sys/socket.h>
#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <string>
#include <vector>
#include "Timestamp.hpp"

class Balancer{

public:
    Balancer(int port, ServersPool* pool, int limit):port(port), pool(pool), limit(limit){}
    void startUdpServer();
    void balancing();
    bool isPacketAllow();

private:
    int port;
    int limit;
    ServersPool* pool;
    int udp_server;
    std::vector<Timestamp> timestamps;
};

#endif