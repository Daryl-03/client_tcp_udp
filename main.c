
#include "util.h"
#include "client.h"

int main() {

//    char msg[] = "Je suis un message de test\n";

//    printf("Sending msg\n");
    send_message_to_addr_udp("Bonjour");
    //send_message_to_addr_tcp();
    printf("Done");
    return 0;
}
