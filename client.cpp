#include "udp_streamer.hpp"

struct custom_message {
    int message_type;
    int message_len;
    char message[128];
};

int main(int argc, char* argv[])
{
    udp_streamer udp_server = udp_streamer("127.0.0.1", 8086);
    custom_message msg;
    msg.message_type = 0;
    sprintf(msg.message, "%s", "hello world");
    msg.message_len = sizeof(msg);

    while (1) {
        udp_server.udp_send((char *)&msg, sizeof(msg));
        sleep(1);
    }

    return 0;
}