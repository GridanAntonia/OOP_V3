#include "Tara.h"

Tara::Tara(const std::string& nume, const std::string& capitala,
          Continent continent, bool populara)
    : nume(nume), capitala(capitala), continent(continent), populara(populara) {}

void swap(Tara& first, Tara& second) {
    using std::swap;
    swap(first.nume, second.nume);
    swap(first.capitala, second.capitala);
    swap(first.continent, second.continent);
    swap(first.populara, second.populara);
}

Tara::Tara(const Tara& other)
    : nume(other.nume), capitala(other.capitala),
      continent(other.continent), populara(other.populara) {}

Tara& Tara::operator=(Tara other) {
    swap(*this, other);
    return *this;
}

std::unique_ptr<Tara> Tara::clone() const {
    return std::make_unique<Tara>(*this);
}

const std::string& Tara::getNume() const { return nume; }
const std::string& Tara::getCapitala() const { return capitala; }
Continent Tara::getContinent() const { return continent; }
bool Tara::estePopulara() const { return populara; }

bool Tara::operator==(const Tara& other) const {
    return nume == other.nume &&
           capitala == other.capitala &&
           continent == other.continent;
}

std::string Tara::getTip() const {
    return "Tara";
}

void Tara::afisare(std::ostream& os) const {
    os << "Tara: " << nume << ", Capitala: " << capitala << ", Continentul: ";
    switch(continent) {
        case Continent::EUROPA: os << "Europa"; break;
        case Continent::AFRICA: os << "Africa"; break;
        case Continent::ASIA: os << "Asia"; break;
        case Continent::AMERICA: os << "America"; break;
        case Continent::TOATE: os << "Toate"; break;
        default: os << "Necunoscut";
    }
}

std::ostream& operator<<(std::ostream& os, const Tara& tara) {
    tara.afisare(os);
    return os;
}



