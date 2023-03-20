#include "Balancer.hpp"

void Balancer::startUdpServer(){
    this->udp_server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if(this->udp_server < 0){ 
        throw std::runtime_error("failed to create socket\n"); 
    }

    struct sockaddr_in local;
    
    local.sin_family = AF_INET;
    local.sin_addr.s_addr = INADDR_ANY;
    local.sin_port = htons( (unsigned short) this->port );
    
    if ( bind( this->udp_server, (const sockaddr*) &local, sizeof(sockaddr_in) ) < 0 ){
        throw std::runtime_error("failed to bind socket\n");
    }
    
    int nonBlocking = 1;

    if ( fcntl(udp_server, F_SETFL, O_NONBLOCK, nonBlocking ) == -1 ){
        throw std::runtime_error("failed to set non-blocking socket\n");
    }
}

bool Balancer::isPacketAllow(){

    if(!timestamps.empty() && timestamps.front().getEllapsedTime() > 1000){
        timestamps.pop(); 
    }

    return timestamps.size() < limit;
}

void Balancer::balancing(){
    int index = 0;
    while(true){
        
        unsigned char packet_data[256];
        unsigned int max_packet_size = sizeof(packet_data);

        sockaddr_in from;
        unsigned int fromLength = sizeof(from);
        int recieved_bytes = recvfrom(udp_server, (char*)packet_data, max_packet_size, 0, (sockaddr*) &from, &fromLength);
        std::cout << "Packet recieved " << packet_data <<std::endl;

        if(!isPacketAllow()){
            std::cout << "Packet dropped" << std::endl;
            continue;
        }
        
        index = (++index) % pool.getServers().size();
        auto dist = pool.getServers()[index].get();
        int sent_bytes = sendto(udp_server, (const char*)packet_data, max_packet_size, 0, (sockaddr*)dist, sizeof(sockaddr_in));
        timestamps.push(Timestamp());
        
        if ( sent_bytes != max_packet_size ){
            throw std::runtime_error("failed to send packet: return value = " + std::to_string(sent_bytes));
        }else{    
            std::cout << "Packet send to server №" << std::to_string(index)<< std::endl;
        }    
    }
}