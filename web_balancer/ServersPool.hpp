#ifndef SERVERS_POOL_HPP
#define SERVERS_POOL_HPP

#include "Config.hpp"
#include <vector>
#include <arpa/inet.h>
#include <memory>


class ServersPool{

public:
    void operator=(const ServersPool&) = delete;

    static ServersPool &getInstance();
    void addServers();
    void setConfig(std::shared_ptr<IConfig>);
    std::vector<std::shared_ptr<sockaddr_in>> getServers() const {return this->servers;}

private:
    std::vector<std::shared_ptr<sockaddr_in>> servers;

protected:
    ServersPool(const ServersPool& other);
    ServersPool() = default;
    
    ~ServersPool(){}

    std::shared_ptr<IConfig> config;
};

#endif