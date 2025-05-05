#ifndef NIVELCAPITALAEUROPA_H
#define NIVELCAPITALAEUROPA_H

#include "Nivel.h"

class NivelCapitalaEuropa : public Nivel {
public:
    NivelCapitalaEuropa();
    
    void afiseazaIntrebare(const Tara* tara) const override;
    bool verificaRaspuns(const Tara* tara, const std::string& raspuns) const override;
    void afiseazaRaspunsCorect(const Tara* tara) const override;
    void getIndiciu(const Tara* tara) const override;
};

#endif // NIVELCAPITALAEUROPA_H