#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include "../common/protocol.hpp"

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation failed.\n";
        return 1;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sock, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Connection failed.\n";
        return 1;
    }

    std::cout << "Connected to server.\n";
    while (true) {
        std::string msg;
        std::cout << "Enter message: ";
        std::getline(std::cin, msg);

        if (msg == "exit") break;

        send(sock, msg.c_str(), msg.length(), 0);

        char buffer[BUFFER_SIZE] = {};
        int bytesReceived = recv(sock, buffer, BUFFER_SIZE - 1, 0);
        if (bytesReceived <= 0) break;

        std::cout << "Server says: " << buffer << "\n";
    }

    close(sock);
    return 0;
}
