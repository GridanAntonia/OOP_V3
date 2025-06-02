#ifndef NIVELCONTINENT_H
#define NIVELCONTINENT_H

#include "Level.h"
#include "Country.h"

class LevelwithContinents : public Level {
public:
    LevelwithContinents();

    void displayQuestion(const Country *country) const override;

    bool checkAnswer(const Country *country, const std::string &answer) const override;

    void displayCorrectAnswer(const Country *country) const override;
};

#endif // NIVELCONTINENT_H
