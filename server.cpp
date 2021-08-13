#include "udp_streamer.hpp"

struct custom_message {
    int message_type;
    int message_len;
    char message[128];
};

int main(int argc, char* argv[])
{
    udp_streamer udp_server = udp_streamer("127.0.0.1", 8086);
    char buf[MSG_BUF_SIZE];
    int size = MSG_BUF_SIZE;
    custom_message msg;

    udp_server.udp_bind();

    while (1) {
        udp_server.udp_recv(buf, size);
        memcpy(&msg, buf, size);

        std::cout << "msg type : " << msg.message_type << std::endl;
        std::cout << "msg len  : " << msg.message_len << std::endl;
        std::cout << "msg      : " << std::string(msg.message) << std::endl;
    }

    return 0;
}