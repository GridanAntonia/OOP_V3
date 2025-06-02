#ifndef JOC_H
#define JOC_H

#include "Player.h"
#include "Level.h"
#include "Ranking.h"
#include <vector>
#include <memory>

class Game {
private:
    static Game* instance;
    Player player;
    std::vector<std::unique_ptr<Level> > levels;
    int currentLevel;
    Ranking ranking;

    void setLevels();

    static std::vector<Country> initialCountries;

    explicit Game(const std::string &playername);
public:

    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    static Game& getInstance(const std::string &playername);
    static void destroyInstance();
    void start();
};

#endif // JOC_H
