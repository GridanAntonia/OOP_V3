#include "LevelwithAllCapitals.h"
#include <iostream>
#include <string>
#include <stdexcept>

LevelwithAllCapitals::LevelwithAllCapitals()
    : Level("Guess the capital of the country (All continents)", 25, 75) {
}

void LevelwithAllCapitals::displayQuestion(const Country *country) const {
    std::cout << "What is the capital of the country " << country->getName() << "?\n";
    std::cout << "Type -hint- to see answer options: ";
}

bool LevelwithAllCapitals::checkAnswer(const Country *country, const std::string &answer) const {
    if (auto multiplechoicecountry = dynamic_cast<const MultipleChoiceCountry *>(country)) {
        try {
            int option = std::stoi(answer);
            const auto &options = multiplechoicecountry->getOptions();
            if (option > 0 && option <= static_cast<int>(options.size())) {
                return options[option - 1] == country->getCapital();
            }
        } catch (...) {
            return answer == country->getCapital();
        }
    }
    return answer == country->getCapital();
}

void LevelwithAllCapitals::displayCorrectAnswer(const Country *country) const {
    std::cout << "The correct capital is " << country->getCapital() << ".\n";
}

void LevelwithAllCapitals::getHint(const Country *country) const {
    if (auto multiplechoicecountry = dynamic_cast<const MultipleChoiceCountry *>(country)) {
        std::cout << "Choose from the following answer options:\n";
        int i = 1;
        for (const auto &option: multiplechoicecountry->getOptions()) {
            std::cout << i++ << ". " << option << "\n";
        }
        std::cout << "Enter the number of the correct variant or the name of the capital: ";
    } else if (!country->getCapital().empty()) {
        std::cout << "The first letter of the capital is:" << country->getCapital().substr(0, 1) << "\n";
    }
}
