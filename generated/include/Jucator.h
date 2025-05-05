#ifndef JUCATOR_H
#define JUCATOR_H

#include <string>
#include <iostream>
#include "Scor.h"

class Jucator {
private:
    std::string numeJucator;
    Scor scorTotal;
    Scor scorCurent;

public:
    explicit Jucator(const std::string& numeJucator);
    
    void actualizeazaScor(int puncte);
    std::string getNume() const;
    int getScorCurent() const;
    int getScorTotal() const;
    void reseteazaScorCurent();
    
    friend std::ostream& operator<<(std::ostream& os, const Jucator& jucator);
};

#endif // JUCATOR_H