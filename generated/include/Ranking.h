#ifndef CLASAMENT_H
#define CLASAMENT_H

#include <vector>
#include <string>
#include <utility>
#include <fstream>

class Ranking {
private:
    static const std::string filename;
    std::vector<std::pair<int, std::string> > scores;

public:
    Ranking();

    void addScore(const std::string &player, int score);

    void displayRanking() const;

    ~Ranking();
};

#endif // CLASAMENT_H
