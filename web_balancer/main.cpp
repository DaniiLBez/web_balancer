#include <iostream>
#include "Config.hpp"
#include "ServersPool.hpp"
#include "Balancer.hpp"
#include "BalancerBuilder.hpp"

int main() {
    
    try{
        IConfig* config = new ConfigJson("../Config.json");
        
        ServersPool* serv_pool = ServersPool::getInstance();
        BalancerBuilder* bb = new BalancerBuilder(config, serv_pool);
        bb->build();
        Balancer* balancer = bb->getBalancer();
        balancer->startUdpServer();
        balancer->balancing();

    }catch(std::exception &e){
        std::cerr << "Runtime_error: "<< e.what();
    }

    return 0;
}
