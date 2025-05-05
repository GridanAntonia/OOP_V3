#ifndef NIVELTARADUPACAPITALA_H
#define NIVELTARADUPACAPITALA_H

#include "Nivel.h"
#include <vector>
#include <string>
#include <random>

class NivelTaraDupaCapitala : public Nivel {
private:
    mutable std::vector<bool> litereDezvaluite;
    mutable std::string TaraCurenta;

    void resetIndiciu() const;
    void literaAleatorie() const;
    void afiseazaTaraCuIndiciu() const;

public:
    NivelTaraDupaCapitala();
    
    void afiseazaIntrebare(const Tara* tara) const override;
    bool verificaRaspuns(const Tara* tara, const std::string& raspuns) const override;
    void afiseazaRaspunsCorect(const Tara* tara) const override;
    void getIndiciu(const Tara* tara) const override;
};

#endif // NIVELTARADUPACAPITALA_H