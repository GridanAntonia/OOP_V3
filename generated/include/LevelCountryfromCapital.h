#ifndef NIVELTARADUPACAPITALA_H
#define NIVELTARADUPACAPITALA_H

#include "Level.h"
#include <vector>
#include <string>
#include <random>

class LevelCountryfromCapital : public Level {
private:
    mutable std::vector<bool> shownletters;
    mutable std::string currentCountry;

    void resetHint() const;

    void randomLetter() const;

    void displayCountryandHint() const;

public:
    LevelCountryfromCapital();

    void displayQuestion(const Country *country) const override;

    bool checkAnswer(const Country *country, const std::string &answer) const override;

    void displayCorrectAnswer(const Country *country) const override;

    void getHint(const Country *country) const override;
};

#endif // NIVELTARADUPACAPITALA_H
