#ifndef LEVELFACTORY_H
#define LEVELFACTORY_H

#include <memory>
#include <stdexcept>

#include "Level.h"
#include "LevelCountryfromCapital.h"
#include "LevelwithAllCapitals.h"
#include "LevelwithContinents.h"
#include "LevelwithEuropeanCapitals.h"
#include "MultipleChoiceCountry.h"

enum class LevelType {
  LevelCountryfromCapital,
  LevelwithAllCapitals,
  LevelwithContinents,
  LevelwithEuropeanCapitals
};

class LevelFactory {
public:
    static std::shared_ptr<Level> CreateLevel(LevelType type) {
        switch(type) {
            case LevelType::LevelCountryfromCapital:
                return std::make_shared<LevelCountryfromCapital>();
            case LevelType::LevelwithAllCapitals:
                return std::make_shared<LevelwithAllCapitals>();
            case LevelType::LevelwithContinents:
                return std::make_shared<LevelwithContinents>();
            case LevelType::LevelwithEuropeanCapitals:
                return std::make_shared<LevelwithEuropeanCapitals>();
            default:
                throw std::runtime_error("Unknown LevelType provided to LevelFactory::CreateLevel");
        }
    }
};

#endif // LEVELFACTORY_H