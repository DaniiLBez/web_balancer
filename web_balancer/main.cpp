#include "Config.hpp"
#include "ServersPool.hpp"
#include "Balancer.hpp"
#include "BalancerBuilder.hpp"

int main() {
    
    try{
        std::shared_ptr<IConfig> config = std::dynamic_pointer_cast<IConfig>(std::make_shared<ConfigJson>("../Config.json"));
        
        auto bb = std::make_unique<BalancerBuilder>(config, ServersPool::getInstance());
        bb->build();
        
        auto balancer = std::move(bb->getBalancer());
        balancer->startUdpServer();
        balancer->balancing();

    }catch(std::exception &e){
        std::cerr << "Runtime_error: "<< e.what();
    }

    return 0;
}
