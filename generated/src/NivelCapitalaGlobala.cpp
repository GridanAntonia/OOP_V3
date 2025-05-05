#include "NivelCapitalaGlobala.h"
#include <iostream>
#include <string>
#include <stdexcept>

NivelCapitalaGlobala::NivelCapitalaGlobala()
    : Nivel("Ghiceste capitala tarii (Toate continentele)", 25, 75) {}

void NivelCapitalaGlobala::afiseazaIntrebare(const Tara* tara) const {
    std::cout << "Care este capitala tarii " << tara->getNume() << "?\n";
    std::cout << "Tasteaza -hint- pentru a vedea variante de raspuns: ";
}

bool NivelCapitalaGlobala::verificaRaspuns(const Tara* tara, const std::string& raspuns) const {
    if (auto taraCuVariante = dynamic_cast<const TaraCuVariante*>(tara)) {
        try {
            int optiune = std::stoi(raspuns);
            const auto& variante = taraCuVariante->getVariante();
            if (optiune > 0 && optiune <= static_cast<int>(variante.size())) {
                return variante[optiune - 1] == tara->getCapitala();
            }
        } catch (...) {
            return raspuns == tara->getCapitala();
        }
    }
    return raspuns == tara->getCapitala();
}

void NivelCapitalaGlobala::afiseazaRaspunsCorect(const Tara* tara) const {
    std::cout << "Capitala corecta este " << tara->getCapitala() << ".\n";
}

void NivelCapitalaGlobala::getIndiciu(const Tara* tara) const {
    if (auto taraCuVariante = dynamic_cast<const TaraCuVariante*>(tara)) {
        std::cout << "Variante de raspuns:\n";
        int i = 1;
        for (const auto& varianta : taraCuVariante->getVariante()) {
            std::cout << i++ << ". " << varianta << "\n";
        }
        std::cout << "Introdu numarul variantei corecte sau numele capitalei: ";
    } else if (!tara->getCapitala().empty()) {
        std::cout << "Prima litera a capitalei este: " << tara->getCapitala().substr(0, 1) << "\n";
    }
}