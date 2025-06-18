#include "game_logic.hpp"
#include <random>
#include <algorithm>
#include <unordered_map>

static const std::string COLORS = "RGBYOP";

MastermindGame::MastermindGame() : attempts(0) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, COLORS.size() - 1);


    std::string shuffled_colors = COLORS;
    std::shuffle(shuffled_colors.begin(), shuffled_colors.end(), gen);

    secret = shuffled_colors.substr(0, 4);  // this is not include duplicate

    // for (int i = 0; i < 4; ++i) {
    //     secret += COLORS[dis(gen)];
    // }
}

std::string MastermindGame::getFeedback(const std::string& guess) {
    attempts++;
    int black = 0, white = 0;
    std::unordered_map<char, int> colorCount;

    for (int i = 0; i < 4; ++i) {
        if (guess[i] == secret[i]) {
            black++;
        } else {
            colorCount[secret[i]]++;
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (guess[i] != secret[i] && colorCount[guess[i]] > 0) {
            white++;
            colorCount[guess[i]]--;
        }
    }

    return std::to_string(black) + "B" + std::to_string(white) + "W";
}

bool MastermindGame::isGameOver() const {
    return attempts >= maxAttempts;
}

bool MastermindGame::isWin(const std::string& guess) const {
    return guess == secret;
}

std::string MastermindGame::getSecret() const {
    return secret;
}
