#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <chrono>

class Timestamp{

private:
    typedef std::chrono::high_resolution_clock::time_point t_point;
    const t_point t_stamp;
public:
    Timestamp():t_stamp(std::chrono::high_resolution_clock::now()){}
    
    int getEllapsedTime() const{
        std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - t_stamp;
		return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    }

};



#endif