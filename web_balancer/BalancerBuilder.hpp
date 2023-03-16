#ifndef BALANCER_BUILDER_HPP
#define BALANCER_BUILDER_HPP

#include "Config.hpp"
#include "ServersPool.hpp"
#include "Balancer.hpp"

class BalancerBuilder{

public:
    BalancerBuilder(IConfig* config, ServersPool* pool):config(config), pool(pool){
        this->pool->setConfig(this->config);
        this->pool->addServers();
    }
    
    ~BalancerBuilder(){
        this->config = nullptr;
        this->pool = nullptr;
        this->balancer = nullptr;
    }

    void build(){
        this->balancer = new Balancer(config->getPort(), pool, config->getLimit());
    }

    Balancer* getBalancer(){return balancer;}
    
protected:
    Balancer* balancer;
private:
    IConfig* config;
    ServersPool* pool;
};

#endif