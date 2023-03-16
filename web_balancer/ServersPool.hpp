#ifndef SERVERS_POOL_HPP
#define SERVERS_POOL_HPP

#include "Config.hpp"
#include <vector>
#include <arpa/inet.h>


class ServersPool{

public:
    void operator=(const ServersPool&) = delete;
    ServersPool(ServersPool& other) = delete;

    static ServersPool *getInstance();
    void addServers();
    void setConfig(IConfig*);
    std::vector<sockaddr_in*> getServers() const {return this->servers;}

    ~ServersPool(){
        for(auto elem: servers){
            delete elem;
        }
    }
    
private:
    std::vector<sockaddr_in*> servers;

protected:
    ServersPool() = default;
    static ServersPool* pool;
    IConfig* config;
};

#endif