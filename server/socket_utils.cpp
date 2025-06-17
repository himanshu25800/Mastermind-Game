// socket_utils.cpp
#include "socket_utils.hpp"
#include <sys/socket.h>
#include <cstring>
#include <iostream>

int setupServerSocket(int port) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);       // it get the file descriptor of socket
    if (server_fd < 0) throw std::runtime_error("Socket creation failed."); // file descriptor will be greater than 2 if success and if fail than negative.

    sockaddr_in server_addr{};  //it is a socket address struct  that let me give u
    // struct sockaddr_in {
    //     sa_family_t    sin_family; // Address family (AF_INET)
    //     in_port_t      sin_port;   // Port number (in network byte order)
    //     struct in_addr sin_addr;   // IP address (in network byte order)
    //     char           sin_zero[8]; // Padding (unused)
    // };

    server_addr.sin_family = AF_INET;  // tells it is of family ipv4
    server_addr.sin_port = htons(port);  // defines the port.
    server_addr.sin_addr.s_addr = INADDR_ANY; // can recieve connection from any ip

    if (bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) < 0)  // bind the server to the address.
        throw std::runtime_error("Bind failed.");
    if (listen(server_fd, 5) < 0)  // starts listening the server i.e., the packet of port no will send here.
        throw std::runtime_error("Listen failed.");

    return server_fd;
}
