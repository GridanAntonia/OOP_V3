#ifndef JUCATOR_H
#define JUCATOR_H

#include <string>
#include <iostream>
#include "Score.h"

class Player {
private:
    std::string name;
    Score<int> TotalScore;
    Score<int> CurrentScore;

public:
    explicit Player(const std::string &name);

    void UpdateScore(int points);

    std::string getName() const;

    int getCurrentScore() const;

    int getTotalScore() const;

    void ResetCurrentScore();

    friend std::ostream &operator<<(std::ostream &os, const Player &player);
};

#endif // JUCATOR_H
