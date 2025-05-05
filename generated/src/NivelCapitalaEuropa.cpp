#include "NivelCapitalaEuropa.h"
#include <iostream>

NivelCapitalaEuropa::NivelCapitalaEuropa() 
    : Nivel("Ghiceste capitala tarii (Europa)", 10, 30) {}

void NivelCapitalaEuropa::afiseazaIntrebare(const Tara* tara) const {
    std::cout << "Care este capitala tarii " << tara->getNume() << "?\n";
    std::cout << "Tasteaza -hint- pentru a descoperi prima litera: ";
}

bool NivelCapitalaEuropa::verificaRaspuns(const Tara* tara, const std::string& raspuns) const {
    if (raspuns == tara->getCapitala())
        return true;
    return isCloseToCorrect(raspuns, tara->getCapitala());
}

void NivelCapitalaEuropa::afiseazaRaspunsCorect(const Tara* tara) const {
    std::cout << "Capitala corecta este " << tara->getCapitala() << ".\n";
}

void NivelCapitalaEuropa::getIndiciu(const Tara* tara) const {
    if (!tara->getCapitala().empty()) {
        std::cout << "Prima litera a capitalei este: " << tara->getCapitala().substr(0, 1) << "\n";
    }
}