#ifndef UDP_STREAMER_H
#define UDP_STREAMER_H

#include <iostream>
#include <sys/types.h>
#include <sys/unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

constexpr int MSG_BUF_SIZE = 256;

class udp_streamer
{
    int sock;
    struct sockaddr_in addr;
public:
    udp_streamer(std::string address, int port);
    void udp_bind();
    void udp_send_msg(std::string msg);
    std::string udp_recv_msg();
    void udp_send(char *buf, int size);
    void udp_recv(char *buf, int size);
    ~udp_streamer();
};

#endif