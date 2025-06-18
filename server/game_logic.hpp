// game_logic.hpp
#pragma once
#include <string>
#include <vector>

class MastermindGame {
private:
    std::string secret;
    int attempts;
    const int maxAttempts = 20;

public:
    MastermindGame();

    std::string getFeedback(const std::string& guess);
    bool isGameOver() const;
    bool isWin(const std::string& guess) const;
    std::string getSecret() const;
};
