#ifndef NIVEL_H
#define NIVEL_H

#include <string>
#include <vector>
#include <memory>
#include "Tara.h"

class Nivel {
protected:
    std::string descriere;
    int punctePerRaspuns;
    int punctajMinim;
    std::vector<std::unique_ptr<Tara>> tari;
    std::vector<std::unique_ptr<Tara>> tariIntrebate;

    bool isCloseToCorrect(const std::string& userAnswer, const std::string& correctAnswer, int maxAllowedDifferences = 2) const;

public:
    Nivel(const std::string& descriere, int punctePerRaspuns, int punctajMinim);
    virtual ~Nivel() = default;

    void adaugaTara(std::unique_ptr<Tara> tara);
    void amestecaTari();
    const Tara* getTaraAleatorie();

    virtual void afiseazaIntrebare(const Tara* tara) const = 0;
    virtual bool verificaRaspuns(const Tara* tara, const std::string& raspuns) const = 0;
    virtual void afiseazaRaspunsCorect(const Tara* tara) const = 0;
    virtual void getIndiciu(const Tara* tara) const;

    const std::string& getDescriere() const;
    int getPunctePerRaspuns() const;
    int getPunctajMinim() const;
    bool esteCompletat(int scor) const;
};

#endif // NIVEL_H