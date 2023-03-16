#include <sys/socket.h>
#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <string>
#include <thread>
#include <chrono>
#include <arpa/inet.h>

int main(){
    struct sockaddr_in peer;
    const size_t EmitIntervalMilliseconds = 100;
    int s;
    peer.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &peer.sin_addr);
    peer.sin_port = htons( (unsigned short) 33333 );
    s = socket(AF_INET, SOCK_DGRAM, 0);
    
    if(s < 0){
        std::cout << "can't create socket\n";
        exit(1);
    }

    int i = 0;

    while(i < 1000){
        int sent_bytes = sendto(s, "hello", 256, 0, (sockaddr*)&peer, sizeof(sockaddr_in));
        i++;
        std::this_thread::sleep_for(std::chrono::milliseconds(EmitIntervalMilliseconds));
    }
}