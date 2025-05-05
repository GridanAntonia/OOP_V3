#ifndef SCOR_H
#define SCOR_H

#include <iostream>

class Scor {
private:
    int puncte;

public:
    Scor();
    explicit Scor(int puncte);
    
    void adaugaPuncte(int valoare);
    int getPuncte() const;
    
    friend std::ostream& operator<<(std::ostream& os, const Scor& scor);
};

#endif // SCOR_H