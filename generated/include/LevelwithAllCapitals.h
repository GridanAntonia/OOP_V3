#ifndef NIVELCAPITALAGLOBALA_H
#define NIVELCAPITALAGLOBALA_H

#include "Level.h"
#include "MultipleChoiceCountry.h"

class LevelwithAllCapitals : public Level {
public:
    LevelwithAllCapitals();

    void displayQuestion(const Country *country) const override;

    bool checkAnswer(const Country *country, const std::string &answer) const override;

    void displayCorrectAnswer(const Country *country) const override;

    void getHint(const Country *country) const override;
};

#endif // NIVELCAPITALAGLOBALA_H
