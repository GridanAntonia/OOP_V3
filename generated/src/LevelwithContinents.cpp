#include "LevelwithContinents.h"
#include <iostream>

LevelwithContinents::LevelwithContinents()
    : Level("Guess the continent of the country", 20, 60) {
}

void LevelwithContinents::displayQuestion(const Country *country) const {
    std::cout << "On what continent is the country " << country->getName() << "?\n";
    std::cout << "Options: Europe, Africa, Asia, America\n";
}

bool LevelwithContinents::checkAnswer(const Country *country, const std::string &answer) const {
    std::string correctContinent;
    switch (country->getContinent()) {
        case Continent::EUROPE: correctContinent = "Europe";
            break;
        case Continent::AFRICA: correctContinent = "Africa";
            break;
        case Continent::ASIA: correctContinent = "Asia";
            break;
        case Continent::AMERICA: correctContinent = "America";
            break;
        default: return false;
    }
    return answer == correctContinent;
}

void LevelwithContinents::displayCorrectAnswer(const Country *country) const {
    std::cout << "The correct continent is: ";
    switch (country->getContinent()) {
        case Continent::EUROPE: std::cout << "Europe";
            break;
        case Continent::AFRICA: std::cout << "Africa";
            break;
        case Continent::ASIA: std::cout << "Asia";
            break;
        case Continent::AMERICA: std::cout << "America";
            break;
        default: std::cout << "Unknown";
    }
    std::cout << ".\n";
}
