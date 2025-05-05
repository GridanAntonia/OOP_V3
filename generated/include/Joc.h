#ifndef JOC_H
#define JOC_H

#include "Jucator.h"
#include "Nivel.h"
#include "Clasament.h"
#include <vector>
#include <memory>

class Joc {
private:
    Jucator jucator;
    std::vector<std::unique_ptr<Nivel>> nivele;
    int nivelCurent;
    Clasament clasament;

    void initializeazaNivele();
    static std::vector<Tara> tariInitiale;

public:
    explicit Joc(const std::string& numeJucator);
    void start();
};

#endif // JOC_H