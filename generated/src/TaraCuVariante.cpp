#include "TaraCuVariante.h"

TaraCuVariante::TaraCuVariante(const std::string& nume,
                             const std::string& capitala,
                             Continent continent,
                             const std::vector<std::string>& variante,
                             bool populara)
    : Tara(nume, capitala, continent, populara),
      varianteRaspuns(variante) {}

std::unique_ptr<Tara> TaraCuVariante::clone() const {
    return std::make_unique<TaraCuVariante>(*this);
}

std::string TaraCuVariante::getTip() const {
    return "TaraCuVariante";
}

const std::vector<std::string>& TaraCuVariante::getVariante() const {
    return varianteRaspuns;
}

void TaraCuVariante::afisare(std::ostream& os) const {
    Tara::afisare(os);
    os << "\nVariante de raspuns:";
    for (const auto& varianta : varianteRaspuns) {
        os << "\n- " << varianta;
    }
}
