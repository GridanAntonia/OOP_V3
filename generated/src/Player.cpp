#include "Player.h"

Player::Player(const std::string &name)
    : name(name), TotalScore(), CurrentScore() {
}

void Player::UpdateScore(int points) {
    CurrentScore.addPoints(points);
    TotalScore.addPoints(points);
}

std::string Player::getName() const {
    return name;
}

int Player::getCurrentScore() const {
    return CurrentScore.getPoints();
}

int Player::getTotalScore() const {
    return TotalScore.getPoints();
}

void Player::ResetCurrentScore() {
    CurrentScore = Score<int>();
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "Player: " << player.name
            << ", Current score: " << player.CurrentScore
            << ", Total Score: " << player.TotalScore;
    return os;
}
