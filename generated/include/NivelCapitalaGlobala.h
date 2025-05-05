#ifndef NIVELCAPITALAGLOBALA_H
#define NIVELCAPITALAGLOBALA_H

#include "Nivel.h"
#include "TaraCuVariante.h"

class NivelCapitalaGlobala : public Nivel {
public:
    NivelCapitalaGlobala();
    
    void afiseazaIntrebare(const Tara* tara) const override;
    bool verificaRaspuns(const Tara* tara, const std::string& raspuns) const override;
    void afiseazaRaspunsCorect(const Tara* tara) const override;
    void getIndiciu(const Tara* tara) const override;
};

#endif // NIVELCAPITALAGLOBALA_H