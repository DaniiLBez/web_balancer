#ifndef CONFIG_INTERFACE_HPP
#define CONFIG_INTERFACE_HPP

#include <fstream>
#include <string>
#include <vector>

class IConfig{

public:
    virtual std::vector<std::string> getAddresses() const = 0;
    virtual int getLimit() const = 0;
    virtual int getPort() const = 0;

protected:
    std::ifstream file;
};


#endif