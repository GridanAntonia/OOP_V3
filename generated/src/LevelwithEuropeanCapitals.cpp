#include "LevelwithEuropeanCapitals.h"
#include <iostream>

LevelwithEuropeanCapitals::LevelwithEuropeanCapitals()
    : Level("Guess the capital of the country (Europe)", 10, 30) {
}

void LevelwithEuropeanCapitals::displayQuestion(const Country *country) const {
    std::cout << "What is the capital of the country " << country->getName() << "?\n";
    std::cout << "Type -hint- to reveal the first letter: ";
}

bool LevelwithEuropeanCapitals::checkAnswer(const Country *country, const std::string &answer) const {
    if (answer == country->getCapital())
        return true;
    return isCloseToCorrect(answer, country->getCapital());
}

void LevelwithEuropeanCapitals::displayCorrectAnswer(const Country *country) const {
    std::cout << "The correct capital is " << country->getCapital() << ".\n";
}

void LevelwithEuropeanCapitals::getHint(const Country *country) const {
    if (!country->getCapital().empty()) {
        std::cout << "The first letter of the capital is: " << country->getCapital().substr(0, 1) << "\n";
    }
}
