cmake_minimum_required(VERSION 3.28)
project(client_tcp_udp C)

set(CMAKE_C_STANDARD 99)

add_executable(client_tcp_udp main.c
        util.c
        util.h
        client.c
        client.h
        client.h
        client.c
)
