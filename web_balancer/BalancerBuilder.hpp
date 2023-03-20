#ifndef BALANCER_BUILDER_HPP
#define BALANCER_BUILDER_HPP

#include "Config.hpp"
#include "ServersPool.hpp"
#include "Balancer.hpp"
#include <memory>

class BalancerBuilder{

public:
    BalancerBuilder(std::shared_ptr<IConfig> config, ServersPool& pool):config(std::move(config)), pool(pool){
        this->pool.setConfig(this->config);
        this->pool.addServers();
    }
    
    ~BalancerBuilder(){
        this->config = nullptr;
        this->balancer = nullptr;
    }

    void build(){
        this->balancer = std::make_unique<Balancer>(config->getPort(), pool, config->getLimit());
    }

    std::unique_ptr<Balancer>& getBalancer(){return balancer;}
    
protected:
    std::unique_ptr<Balancer> balancer;
private:
    std::shared_ptr<IConfig> config;
    ServersPool& pool;
};

#endif