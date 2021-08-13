#include <iostream>
#include <sys/types.h>
#include <sys/unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

#include "udp_streamer.hpp"

udp_streamer::udp_streamer(std::string address, int port)
{
    this->sock = socket(AF_INET, SOCK_DGRAM, 0);
    this->addr.sin_family = AF_INET;
    this->addr.sin_addr.s_addr = inet_addr(address.c_str());
    this->addr.sin_port = htons(port);
}

void udp_streamer::udp_bind()
{
    bind(this->sock, (const struct sockaddr *)&this->addr, sizeof(this->addr));
}

void udp_streamer::udp_send_msg(std::string msg)
{
    sendto(this->sock, msg.c_str(), msg.length(), 0, (struct sockaddr*)&this->addr, sizeof(this->addr));
}

std::string udp_streamer::udp_recv_msg()
{
    char buf[MSG_BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    recv(this->sock, buf, sizeof(buf), 0);
    return std::string(buf);
}

void udp_streamer::udp_send(char *buf, int size)
{
    sendto(this->sock, buf, size, 0, (struct sockaddr*)&this->addr, sizeof(this->addr));
}

void udp_streamer::udp_recv(char *buf, int size)
{
    memset(buf, 0, size);
    recv(this->sock, buf, size, 0);
}

udp_streamer::~udp_streamer()
{
    close(this->sock);
}
