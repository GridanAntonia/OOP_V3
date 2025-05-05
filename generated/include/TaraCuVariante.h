
#ifndef TARACUVARIANTE_H
#define TARACUVARIANTE_H

#include "tara.h"
#include <vector>
#include <string>
#include <memory>

class TaraCuVariante : public Tara {
private:
    std::vector<std::string> varianteRaspuns;

public:
    TaraCuVariante(const std::string& nume,
                  const std::string& capitala,
                  Continent continent,
                  const std::vector<std::string>& variante,
                  bool populara = false);

    std::unique_ptr<Tara> clone() const override;
    std::string getTip() const override;
    const std::vector<std::string>& getVariante() const;
    void afisare(std::ostream& os) const override;
};


#endif //TARACUVARIANTE_H
