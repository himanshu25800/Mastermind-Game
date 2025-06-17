#include <iostream>
#include <cstring>
#include <unistd.h>
#include "../common/protocol.hpp"
#include "socket_utils.hpp"

int main() {
    try {
        int serverSocket = setupServerSocket(SERVER_PORT);
        std::cout << "Server listening on port " << SERVER_PORT << "...\n";

        sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int clientSocket = accept(serverSocket, (sockaddr*)&client_addr, &client_len);

        char buffer[BUFFER_SIZE];
        while (true) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytesRead = read(clientSocket, buffer, BUFFER_SIZE - 1);
            if (bytesRead <= 0) break;

            std::cout << "Received from client: " << buffer;
            std::string reply = "Server echo: ";
            reply += buffer;
            send(clientSocket, reply.c_str(), reply.length(), 0);
        }

        close(clientSocket);
        close(serverSocket);
    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
    return 0;
}
