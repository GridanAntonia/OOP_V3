#include "Scor.h"

Scor::Scor() : puncte(0) {}

Scor::Scor(int puncte) : puncte(puncte) {}

void Scor::adaugaPuncte(int valoare) {
    puncte += valoare;
}

int Scor::getPuncte() const {
    return puncte;
}

std::ostream& operator<<(std::ostream& os, const Scor& scor) {
    os << "Scor: " << scor.puncte;
    return os;
}
