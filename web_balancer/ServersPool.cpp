#include "ServersPool.hpp"

ServersPool* ServersPool::pool = nullptr;

ServersPool* ServersPool::getInstance(){
    if(!pool){
        pool = new ServersPool();
    }
    return pool;
}

void ServersPool::addServers(){
    for(auto& elem: this->config->getAddresses()){
        
        int delim_pos = elem.find(':');

        sockaddr_in* address = new sockaddr_in();

        address->sin_family = AF_INET;
        inet_pton(AF_INET, elem.substr(0, delim_pos).c_str(), &address->sin_addr);
        address->sin_port = htons(std::atoi(elem.substr(delim_pos+1).c_str()));
        
        this->servers.push_back(address);
    }
}

void ServersPool::setConfig(IConfig* config){
    this->config = config;
}
