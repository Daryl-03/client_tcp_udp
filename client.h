//
// Created by Naku on 28/02/2024.
//

#ifndef SOCKET_CLIENT_H
#define SOCKET_CLIENT_H

#include "util.h"
#define TAILLE_BUFFER 1024
#define PORT 4000
//#define HOASTADDR "192.168.1.66"
#define HOSTADDR "192.168.163.152"

SOCKET create_socket(int type);
void send_message_to_addr_udp(char* msg);

void send_message_to_addr_tcp();

#endif //SOCKET_CLIENT_H
