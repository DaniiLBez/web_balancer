#include "ServersPool.hpp"

ServersPool& ServersPool::getInstance(){
    static ServersPool pool;
    return pool;
}

void ServersPool::addServers(){
    for(auto& elem: this->config->getAddresses()){
        
        int delim_pos = elem.find(':');

        auto address = std::make_shared<sockaddr_in>();

        address->sin_family = AF_INET;
        inet_pton(AF_INET, elem.substr(0, delim_pos).c_str(), &address->sin_addr);
        address->sin_port = htons(std::atoi(elem.substr(delim_pos+1).c_str()));
        
        this->servers.push_back(address);
    }
}

void ServersPool::setConfig(std::shared_ptr<IConfig> config){
    this->config = std::move(config);
}
