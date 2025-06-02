#ifndef TARA_H
#define TARA_H

#include <iostream>
#include <string>
#include <memory>

enum class Continent {
    EUROPE,
    AFRICA,
    ASIA,
    AMERICA,
    TOATE
};

class Country {
private:
    std::string name;
    std::string capital;
    Continent continent;
    bool popular;

public:
    explicit Country(const std::string &name, const std::string &capital,
                     Continent continent, bool popular = false);

    Country(const Country &other);

    Country &operator=(Country other);

    friend void swap(Country &first, Country &second);

    virtual std::unique_ptr<Country> clone() const;

    const std::string &getName() const;

    const std::string &getCapital() const;

    Continent getContinent() const;

    bool isPopular() const;

    bool operator==(const Country &other) const;

    virtual std::string getType() const;

    virtual void display(std::ostream &os) const;

    friend std::ostream &operator<<(std::ostream &os, const Country &country);
};

#endif // TARA_H
