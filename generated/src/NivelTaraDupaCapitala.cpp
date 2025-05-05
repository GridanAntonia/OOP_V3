#include "NivelTaraDupaCapitala.h"
#include <iostream>
#include <random>

NivelTaraDupaCapitala::NivelTaraDupaCapitala()
    : Nivel("Ghiceste tara care are aceasta capitala", 15, 45) {}

void NivelTaraDupaCapitala::resetIndiciu() const {
    litereDezvaluite.clear();
    if (!TaraCurenta.empty()) {
        litereDezvaluite.resize(TaraCurenta.size(), false);
    }
}

void NivelTaraDupaCapitala::literaAleatorie() const {
    std::vector<int> litereIndisponibile;
    for (int i = 0; i < TaraCurenta.size(); i++) {
        if (!litereDezvaluite[i] && TaraCurenta[i] != ' ') {
            litereIndisponibile.push_back(i);
        }
    }
    if (!litereIndisponibile.empty()) {
        std::mt19937 rng(std::random_device{}());
        std::uniform_int_distribution<int> dist(0, litereIndisponibile.size() - 1);
        int index = litereIndisponibile[dist(rng)];
        litereDezvaluite[index] = true;
    }
}

void NivelTaraDupaCapitala::afiseazaTaraCuIndiciu() const {
    for (int i = 0; i < TaraCurenta.size(); i++) {
        if (litereDezvaluite[i] || TaraCurenta[i] == ' ') {
            std::cout << TaraCurenta[i];
        }
        else {
            std::cout << '_';
        }
    }
    std::cout << '\n';
}

void NivelTaraDupaCapitala::afiseazaIntrebare(const Tara* tara) const {
    TaraCurenta = tara->getNume();
    resetIndiciu();
    std::cout << "Care este tara care are capitala " << tara->getCapitala() << "?\n";
    std::cout << "Tasteaza -hint- pentru indicii progresivi: ";
}

bool NivelTaraDupaCapitala::verificaRaspuns(const Tara* tara, const std::string& raspuns) const {
    return raspuns == tara->getNume();
}

void NivelTaraDupaCapitala::afiseazaRaspunsCorect(const Tara* tara) const {
    std::cout << "Tara corecta este " << tara->getNume() << ".\n";
}

void NivelTaraDupaCapitala::getIndiciu(const Tara* tara) const {
    if (TaraCurenta != tara->getNume()) {
        TaraCurenta = tara->getNume();
        resetIndiciu();
    }

    if (litereDezvaluite.empty()) {
        litereDezvaluite.resize(TaraCurenta.size(), false);
        std::cout << "Tara are " << TaraCurenta.size() << " litere: ";
        for (size_t i = 0; i < TaraCurenta.size(); ++i) {
            if (TaraCurenta[i] == ' ') {
                std::cout << ' ';
                litereDezvaluite[i] = true;
            } else {
                std::cout << '_';
            }
        }
        std::cout << '\n';
    } else {
        literaAleatorie();
        std::cout << "Indiciu: ";
        afiseazaTaraCuIndiciu();
    }
}//
// Created by Vio on 5/5/2025.
//
