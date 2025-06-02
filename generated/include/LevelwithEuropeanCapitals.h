#ifndef NIVELCAPITALAEUROPA_H
#define NIVELCAPITALAEUROPA_H

#include "Level.h"

class LevelwithEuropeanCapitals : public Level {
public:
    LevelwithEuropeanCapitals();

    void displayQuestion(const Country *country) const override;

    bool checkAnswer(const Country *country, const std::string &answer) const override;

    void displayCorrectAnswer(const Country *country) const override;

    void getHint(const Country *country) const override;
};

#endif // NIVELCAPITALAEUROPA_H
