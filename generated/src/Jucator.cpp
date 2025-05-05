#include "Jucator.h"

Jucator::Jucator(const std::string& numeJucator) 
    : numeJucator(numeJucator), scorTotal(), scorCurent() {}

void Jucator::actualizeazaScor(int puncte) {
    scorCurent.adaugaPuncte(puncte);
    scorTotal.adaugaPuncte(puncte);
}

std::string Jucator::getNume() const {
    return numeJucator;
}

int Jucator::getScorCurent() const {
    return scorCurent.getPuncte();
}

int Jucator::getScorTotal() const {
    return scorTotal.getPuncte();
}

void Jucator::reseteazaScorCurent() {
    scorCurent = Scor();
}

std::ostream& operator<<(std::ostream& os, const Jucator& jucator) {
    os << "Jucator: " << jucator.numeJucator 
       << ", Scor curent: " << jucator.scorCurent
       << ", Scor total: " << jucator.scorTotal;
    return os;
}