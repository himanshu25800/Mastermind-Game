#include "../common/protocol.hpp"
#include "socket_utils.hpp"
#include "game_logic.hpp"

int main() {
    try {
        int serverSocket = setupServerSocket(SERVER_PORT);
        std::cout << "Server listening on port " << SERVER_PORT << "...\n";

        sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int clientSocket = accept(serverSocket, (sockaddr*)&client_addr, &client_len);

        MastermindGame game;
        char buffer[BUFFER_SIZE];

        while (true) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytesRead = read(clientSocket, buffer, BUFFER_SIZE - 1);
            if (bytesRead <= 0) break;

            std::string guess(buffer);
            guess.erase(std::remove(guess.begin(), guess.end(), '\n'), guess.end());

            if (guess.size() != 4) {
                std::string error = "Invalid input. Guess must be 4 letters.\n";
                send(clientSocket, error.c_str(), error.size(), 0);
                continue;
            }

            if (game.isWin(guess)) {
                std::string winMsg = "WIN\n";
                send(clientSocket, winMsg.c_str(), winMsg.length(), 0);
                break;
            }

            std::string feedback = game.getFeedback(guess);
            if (game.isGameOver()) {
                std::string loseMsg = "LOSE " + game.getSecret() + "\n";
                send(clientSocket, loseMsg.c_str(), loseMsg.length(), 0);
                break;
            } else {
                feedback += "\n";
                send(clientSocket, feedback.c_str(), feedback.length(), 0);
            }
        }

        close(clientSocket);
        close(serverSocket);
    } catch (const std::exception &ex) {
        std::cerr << "Error: " << ex.what() << "\n";
    }
    return 0;
}
