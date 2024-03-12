//
// Created by Naku on 28/02/2024.
//

#include "client.h"


// création du socket



// envoyer un message
void send_message_to_addr_udp(char* msg){
    char buffer[TAILLE_BUFFER];
    SOCKET sock = create_socket(SOCK_DGRAM);

    SOCKADDR_IN to = {0};

    to.sin_addr.s_addr = inet_addr(HOSTADDR);
    to.sin_port = htons(PORT);
    to.sin_family = AF_INET;

    if(sendto(sock, msg, strlen(msg), 0, (SOCKADDR *)&to, sizeof(to)) < 0){
        perror("sendto");
        exit(EXIT_FAILURE);
    }
    printf("sent");
    int size = sizeof(to);

    if(recvfrom(sock, buffer, strlen(buffer)-1, 0, (SOCKADDR *)&to, &size) < 0){
        perror("receiveFRom");
        exit(EXIT_FAILURE);
    }

    buffer[strlen(buffer)] = '\0';

    printf("Message recu : %s\n", buffer);
}

void send_message_to_addr_tcp(){
    char buffer[TAILLE_BUFFER];
    SOCKET sock = create_socket(SOCK_STREAM);

    SOCKADDR_IN to = {0};

    to.sin_addr.s_addr = inet_addr(HOSTADDR); // inet_addr(addr) permet de convertir une adresse IP en un entier
    to.sin_port = htons(PORT);
    to.sin_family = AF_INET;

    if(connect(sock, (SOCKADDR *)&to, sizeof(to)) == SOCKET_ERROR){
        perror("connect");
        exit(EXIT_FAILURE);
    }

    while(1){
        printf("Entrez un message : ");
        fgets(buffer, TAILLE_BUFFER, stdin);
        write_socket_tcp(sock, buffer, strlen(buffer));
        if(strcmp(buffer, "fin\n") == 0){
            break;
        }
    }

    closesocket(sock);
}
