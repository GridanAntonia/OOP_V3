#include "NivelContinent.h"
#include <iostream>

NivelContinent::NivelContinent() 
    : Nivel("Ghiceste continentul tarii", 20, 60) {}

void NivelContinent::afiseazaIntrebare(const Tara* tara) const {
    std::cout << "Pe ce continent se afla tara " << tara->getNume() << "?\n";
    std::cout << "Optiuni: Europa, Africa, Asia, America\n";
}

bool NivelContinent::verificaRaspuns(const Tara* tara, const std::string& raspuns) const {
    std::string continentCorect;
    switch(tara->getContinent()) {
        case Continent::EUROPA: continentCorect = "Europa"; break;
        case Continent::AFRICA: continentCorect = "Africa"; break;
        case Continent::ASIA: continentCorect = "Asia"; break;
        case Continent::AMERICA: continentCorect = "America"; break;
        default: return false;
    }
    return raspuns == continentCorect;
}

void NivelContinent::afiseazaRaspunsCorect(const Tara* tara) const {
    std::cout << "Continentul corect este: ";
    switch(tara->getContinent()) {
        case Continent::EUROPA: std::cout << "Europa"; break;
        case Continent::AFRICA: std::cout << "Africa"; break;
        case Continent::ASIA: std::cout << "Asia"; break;
        case Continent::AMERICA: std::cout << "America"; break;
        default: std::cout << "Necunoscut";
    }
    std::cout << ".\n";
}