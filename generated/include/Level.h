#ifndef NIVEL_H
#define NIVEL_H

#include <string>
#include <vector>
#include <memory>
#include "Country.h"

class Level {
protected:
    std::string description;
    int pointsPerAnswer;
    int minimum;
    std::vector<std::unique_ptr<Country> > countries;
    std::vector<std::unique_ptr<Country> > usedCountries;

    bool isCloseToCorrect(const std::string &userAnswer, const std::string &correctAnswer,
                          int maxAllowedDifferences = 2) const;

public:
    Level(const std::string &description, int pointsPerAnswer, int minimum);

    virtual ~Level() = default;

    void addCountry(std::unique_ptr<Country> country);

    void shuffle();

    const Country *getRandomCountry();

    virtual void displayQuestion(const Country *country) const = 0;

    virtual bool checkAnswer(const Country *country, const std::string &answer) const = 0;

    virtual void displayCorrectAnswer(const Country *country) const = 0;

    virtual void getHint(const Country *country) const;

    const std::string &getDescription() const;

    int getPointsPerAnswer() const;

    int getMinimum() const;

    bool isCompleted(int score) const;
};

#endif // NIVEL_H
