#ifndef NIVELCONTINENT_H
#define NIVELCONTINENT_H

#include "Nivel.h"
#include "Tara.h"

class NivelContinent : public Nivel {
public:
    NivelContinent();
    
    void afiseazaIntrebare(const Tara* tara) const override;
    bool verificaRaspuns(const Tara* tara, const std::string& raspuns) const override;
    void afiseazaRaspunsCorect(const Tara* tara) const override;
};

#endif // NIVELCONTINENT_H