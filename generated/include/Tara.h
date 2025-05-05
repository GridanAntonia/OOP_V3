#ifndef TARA_H
#define TARA_H

#include <iostream>
#include <string>
#include <memory>

enum class Continent {
    EUROPA,
    AFRICA,
    ASIA,
    AMERICA,
    TOATE
};

class Tara {
private:
    std::string nume;
    std::string capitala;
    Continent continent;
    bool populara;
public:

    explicit Tara(const std::string& nume, const std::string& capitala,
                Continent continent, bool populara = false);

    Tara(const Tara& other);
    Tara& operator=(Tara other);
    friend void swap(Tara& first, Tara& second);

    virtual std::unique_ptr<Tara> clone() const;

    const std::string& getNume() const;
    const std::string& getCapitala() const;
    Continent getContinent() const;
    bool estePopulara() const;

    bool operator==(const Tara& other) const;

    virtual std::string getTip() const;
    virtual void afisare(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Tara& tara);
};

#endif // TARA_H