#ifndef CONFIG_JSON_HPP
#define CONFIG_JSON_HPP

#include "IConfig.hpp"
#include <jsoncpp/json/json.h>

class ConfigJson: public IConfig{

private:
    std::vector<std::string> addresses;
    int port;
    int limit;

public:
    ConfigJson(std::string filename = "./Config.json"){
        this->file.open(filename, std::ifstream::binary);
        if(!this->file.is_open()){
            throw std::runtime_error("Unable to open configuration file\n");
        }
        Json::Value config;
        this->file >> config;

        this->limit = config["Limit"].asInt();
        this->port = config["Port"].asInt();

        for(auto& elem: config["IPs"]){
            this->addresses.push_back(elem.asString());
        }
    };

    std::vector<std::string> getAddresses() const {return this->addresses;};
    int getPort() const {return this->port;};
    int getLimit() const {return this->limit;};

    ~ConfigJson(){
        file.close();
    }
    
protected:
    std::ifstream file;
};

#endif