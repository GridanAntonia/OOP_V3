#include "LevelCountryfromCapital.h"
#include <iostream>
#include <random>

LevelCountryfromCapital::LevelCountryfromCapital()
    : Level("Guess the country that has this capital", 15, 45) {
}

void LevelCountryfromCapital::resetHint() const{
    shownletters.clear();
    if (!currentCountry.empty()) {
        shownletters.resize(currentCountry.size(), false);
    }
}

void LevelCountryfromCapital::randomLetter() const {
    std::vector<int> usedLetters;
    for (int i = 0; i < currentCountry.size(); i++) {
        if (!shownletters[i] && currentCountry[i] != ' ') {
            usedLetters.push_back(i);
        }
    }
    if (!usedLetters.empty()) {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(0, usedLetters.size() - 1);
        int index = usedLetters[dist(rng)];
        shownletters[index] = true;
    }
}

void LevelCountryfromCapital::displayCountryandHint() const {
    for (int i = 0; i < currentCountry.size(); i++) {
        if (shownletters[i] || currentCountry[i] == ' ') {
            std::cout << currentCountry[i];
        } else {
            std::cout << '_';
        }
    }
    std::cout << '\n';
}

void LevelCountryfromCapital::displayQuestion(const Country *country) const {
    currentCountry = country->getName();
    resetHint();
    std::cout << "Which country has the capital " << country->getCapital() << "?\n";
    std::cout << "Type -hint- for progressive hints: ";
}

bool LevelCountryfromCapital::checkAnswer(const Country *country, const std::string &answer) const {
    return answer == country->getName();
}

void LevelCountryfromCapital::displayCorrectAnswer(const Country *country) const {
    std::cout << "The correct country is " << country->getName() << ".\n";
}

void LevelCountryfromCapital::getHint(const Country *country) const {
    if (currentCountry != country->getName()) {
        currentCountry = country->getName();
        resetHint();
    }

    if (shownletters.empty()) {
        shownletters.resize(currentCountry.size(), false);
        std::cout << "The country has " << currentCountry.size() << " litere: ";
        for (size_t i = 0; i < currentCountry.size(); ++i) {
            if (currentCountry[i] == ' ') {
                std::cout << ' ';
                shownletters[i] = true;
            } else {
                std::cout << '_';
            }
        }
        std::cout << '\n';
    } else {
        randomLetter();
        std::cout << "Hint: ";
        displayCountryandHint();
    }
}
