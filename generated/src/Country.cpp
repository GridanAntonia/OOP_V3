#include "Country.h"

Country::Country(const std::string &name, const std::string &capital,
           Continent continent, bool popular)
    : name(name), capital(capital), continent(continent), popular(popular) {
}

void swap(Country &first, Country &second) {
    using std::swap;
    swap(first.name, second.name);
    swap(first.capital, second.capital);
    swap(first.continent, second.continent);
    swap(first.popular, second.popular);
}

Country::Country(const Country &other)
    : name(other.name), capital(other.capital),
      continent(other.continent), popular(other.popular) {
}

Country &Country::operator=(Country other) {
    swap(*this, other);
    return *this;
}

std::unique_ptr<Country> Country::clone() const {
    return std::make_unique<Country>(*this);
}

const std::string &Country::getName() const { return name; }
const std::string &Country::getCapital() const { return capital; }
Continent Country::getContinent() const { return continent; }
bool Country::isPopular() const { return popular; }

bool Country::operator==(const Country &other) const {
    return name == other.name &&
           capital == other.capital &&
           continent == other.continent;
}

std::string Country::getType() const {
    return "Tara";
}

void Country::display(std::ostream &os) const {
    os << "Country: " << name << ", Capital: " << capital << ", Continent: ";
    switch (continent) {
        case Continent::EUROPE: os << "Europe";
            break;
        case Continent::AFRICA: os << "Africa";
            break;
        case Continent::ASIA: os << "Asia";
            break;
        case Continent::AMERICA: os << "America";
            break;
        case Continent::TOATE: os << "All";
            break;
        default: os << "Unknown";
    }
}

std::ostream &operator<<(std::ostream &os, const Country &tara) {
    tara.display(os);
    return os;
}
