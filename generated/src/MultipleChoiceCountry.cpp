#include "MultipleChoiceCountry.h"

MultipleChoiceCountry::MultipleChoiceCountry(const std::string &name,
                                             const std::string &capital,
                                             Continent continent,
                                             const std::vector<std::string> &multiplechoices,
                                             bool popular)
    : Country(name, capital, continent, popular),
      multipleChoices(multiplechoices) {
}

std::unique_ptr<Country> MultipleChoiceCountry::clone() const {
    return std::make_unique<MultipleChoiceCountry>(*this);
}

std::string MultipleChoiceCountry::getType() const {
    return "MultipleChoiceCountry";
}

const std::vector<std::string> &MultipleChoiceCountry::getOptions() const {
    return multipleChoices;
}

void MultipleChoiceCountry::display(std::ostream &os) const {
    Country::display(os);
    os << "\nSelect one answear from the list:";
    for (const auto &varianta: multipleChoices) {
        os << "\n- " << varianta;
    }
}
