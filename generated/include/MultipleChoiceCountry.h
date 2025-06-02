#ifndef TARACUVARIANTE_H
#define TARACUVARIANTE_H

#include "Country.h"
#include <vector>
#include <string>
#include <memory>

class MultipleChoiceCountry : public Country {
private:
    std::vector<std::string> multipleChoices;

public:
    MultipleChoiceCountry();
    MultipleChoiceCountry(const std::string &name,
                   const std::string &capital,
                   Continent continent,
                   const std::vector<std::string> &multipleChoices,
                   bool popular = false);

    std::unique_ptr<Country> clone() const override;

    std::string getType() const override;

    const std::vector<std::string> &getOptions() const;

    void display(std::ostream &os) const override;
};


#endif //TARACUVARIANTE_H
