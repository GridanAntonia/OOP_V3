#include <iostream>
#include <array>
#include "Ranking.h"
#include "Errors.h"
#include "Game.h"
#include "Player.h"
#include "Level.h"
#include "LevelwithContinents.h"
#include "LevelwithEuropeanCapitals.h"
#include "LevelwithAllCapitals.h"
#include "LevelCountryfromCapital.h"
#include "Score.h"
#include "Country.h"
#include "MultipleChoiceCountry.h"


int main() {
    std::string name;
    std::cout << "Write your name: ";
    std::getline(std::cin, name);

    // Used Singleton for Game, because there is only one game I want to start.
    // After finishing the quiz, it can be deleted.
    Game& game = Game::getInstance(name);
    game.start();
    Game::destroyInstance();
    return 0;
}
