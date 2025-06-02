#include "Game.h"
#include "LevelwithContinents.h"
#include "LevelCountryfromCapital.h"
#include "LevelwithAllCapitals.h"
#include "LevelwithEuropeanCapitals.h"
#include "MultipleChoiceCountry.h"
#include <iostream>
#include <algorithm>
#include <random>

Game *Game::instance = nullptr;

std::vector<Country> Game::initialCountries = {
    Country("Afghanistan", "Kabul", Continent::ASIA, false),
    Country("South Africa", "Pretoria", Continent::AFRICA, false),
    Country("Albania", "Tirana", Continent::EUROPE, true),
    Country("Algeria", "Algiers", Continent::AFRICA, false),
    Country("Andorra", "Andorra la Vella", Continent::EUROPE, true),
    Country("Angola", "Luanda", Continent::AFRICA, false),
    Country("Antigua and Barbuda", "Saint John's", Continent::AMERICA, false),
    Country("Saudi Arabia", "Riyadh", Continent::ASIA, false),
    Country("Argentina", "Buenos Aires", Continent::AMERICA, false),
    Country("Armenia", "Yerevan", Continent::ASIA, false),
    Country("Austria", "Vienna", Continent::EUROPE, true),
    Country("Azerbaijan", "Baku", Continent::ASIA, false),
    Country("Bahamas", "Nassau", Continent::AMERICA, false),
    Country("Bahrain", "Manama", Continent::ASIA, false),
    Country("Bangladesh", "Dhaka", Continent::ASIA, false),
    Country("Barbados", "Bridgetown", Continent::AMERICA, false),
    Country("Belarus", "Minsk", Continent::EUROPE, true),
    Country("Belgium", "Brussels", Continent::EUROPE, true),
    Country("Belize", "Belmopan", Continent::AMERICA, false),
    Country("Benin", "Porto-Novo", Continent::AFRICA, false),
    Country("Bhutan", "Thimphu", Continent::ASIA, false),
    Country("Bolivia", "Sucre", Continent::AMERICA, false),
    Country("Bosnia and Herzegovina", "Sarajevo", Continent::EUROPE, true),
    Country("Botswana", "Gaborone", Continent::AFRICA, false),
    Country("Brazil", "Brasília", Continent::AMERICA, false),
    Country("Brunei", "Bandar Seri Begawan", Continent::ASIA, false),
    Country("Bulgaria", "Sofia", Continent::EUROPE, true),
    Country("Burkina Faso", "Ouagadougou", Continent::AFRICA, false),
    Country("Burundi", "Gitega", Continent::AFRICA, false),
    Country("Cambodia", "Phnom Penh", Continent::ASIA, false),
    Country("Cameroon", "Yaoundé", Continent::AFRICA, false),
    Country("Canada", "Ottawa", Continent::AMERICA, false),
    Country("Cape Verde", "Praia", Continent::AFRICA, false),
    Country("Czech Republic", "Prague", Continent::EUROPE, true),
    Country("Chile", "Santiago", Continent::AMERICA, false),
    Country("China", "Beijing", Continent::ASIA, false),
    Country("Cyprus", "Nicosia", Continent::EUROPE, true),
    Country("Colombia", "Bogotá", Continent::AMERICA, false),
    Country("Comoros", "Moroni", Continent::AFRICA, false),
    Country("Republic of the Congo", "Brazzaville", Continent::AFRICA, false),
    Country("Democratic Republic of the Congo", "Kinshasa", Continent::AFRICA, false),
    Country("North Korea", "Pyongyang", Continent::ASIA, false),
    Country("South Korea", "Seoul", Continent::ASIA, false),
    Country("Costa Rica", "San José", Continent::AMERICA, false),
    Country("Croatia", "Zagreb", Continent::EUROPE, true),
    Country("Cuba", "Havana", Continent::AMERICA, false),
    Country("Denmark", "Copenhagen", Continent::EUROPE, true),
    Country("Djibouti", "Djibouti", Continent::AFRICA, false),
    Country("Dominica", "Roseau", Continent::AMERICA, false),
    Country("Ecuador", "Quito", Continent::AMERICA, false),
    Country("Egypt", "Cairo", Continent::AFRICA, false),
    Country("El Salvador", "San Salvador", Continent::AMERICA, false),
    Country("Switzerland", "Bern", Continent::EUROPE, true),
    Country("United Arab Emirates", "Abu Dhabi", Continent::ASIA, false),
    Country("Eritrea", "Asmara", Continent::AFRICA, false),
    Country("Estonia", "Tallinn", Continent::EUROPE, true),
    Country("Eswatini", "Mbabane", Continent::AFRICA, false),
    Country("Ethiopia", "Addis Ababa", Continent::AFRICA, false),
    Country("Philippines", "Manila", Continent::ASIA, false),
    Country("Finland", "Helsinki", Continent::EUROPE, true),
    Country("France", "Paris", Continent::EUROPE, true),
    Country("Gabon", "Libreville", Continent::AFRICA, false),
    Country("Gambia", "Banjul", Continent::AFRICA, false),
    Country("Georgia", "Tbilisi", Continent::ASIA, false),
    Country("Germany", "Berlin", Continent::EUROPE, true),
    Country("Ghana", "Accra", Continent::AFRICA, false),
    Country("Greece", "Athens", Continent::EUROPE, true),
    Country("Grenada", "Saint George's", Continent::AMERICA, false),
    Country("Guatemala", "Guatemala City", Continent::AMERICA, false),
    Country("Guinea", "Conakry", Continent::AFRICA, false),
    Country("Guinea-Bissau", "Bissau", Continent::AFRICA, false),
    Country("Equatorial Guinea", "Malabo", Continent::AFRICA, false),
    Country("Guyana", "Georgetown", Continent::AMERICA, false),
    Country("Haiti", "Port-au-Prince", Continent::AMERICA, false),
    Country("Honduras", "Tegucigalpa", Continent::AMERICA, false),
    Country("India", "New Delhi", Continent::ASIA, false),
    Country("Indonesia", "Jakarta", Continent::ASIA, false),
    Country("Jordan", "Amman", Continent::ASIA, false),
    Country("Iraq", "Baghdad", Continent::ASIA, false),
    Country("Iran", "Tehran", Continent::ASIA, false),
    Country("Ireland", "Dublin", Continent::EUROPE, true),
    Country("Iceland", "Reykjavik", Continent::EUROPE, true),
    Country("Israel", "Jerusalem", Continent::ASIA, false),
    Country("Italy", "Rome", Continent::EUROPE, true),
    Country("Jamaica", "Kingston", Continent::AMERICA, false),
    Country("Japan", "Tokyo", Continent::ASIA, false),
    Country("Kazakhstan", "Nur-Sultan", Continent::ASIA, false),
    Country("Kenya", "Nairobi", Continent::AFRICA, false),
    Country("Kuwait", "Kuwait City", Continent::ASIA, false),
    Country("Kyrgyzstan", "Bishkek", Continent::ASIA, false),
    Country("Laos", "Vientiane", Continent::ASIA, false),
    Country("Latvia", "Riga", Continent::EUROPE, true),
    Country("Lebanon", "Beirut", Continent::ASIA, false),
    Country("Lesotho", "Maseru", Continent::AFRICA, false),
    Country("Liberia", "Monrovia", Continent::AFRICA, false),
    Country("Libya", "Tripoli", Continent::AFRICA, false),
    Country("Liechtenstein", "Vaduz", Continent::EUROPE, true),
    Country("Lithuania", "Vilnius", Continent::EUROPE, true),
    Country("Luxembourg", "Luxembourg", Continent::EUROPE, true),
    Country("Madagascar", "Antananarivo", Continent::AFRICA, false),
    Country("Malawi", "Lilongwe", Continent::AFRICA, false),
    Country("Malaysia", "Kuala Lumpur", Continent::ASIA, false),
    Country("Maldives", "Malé", Continent::ASIA, false),
    Country("Mali", "Bamako", Continent::AFRICA, false),
    Country("Malta", "Valletta", Continent::EUROPE, true),
    Country("Morocco", "Rabat", Continent::AFRICA, false),
    Country("Mauritania", "Nouakchott", Continent::AFRICA, false),
    Country("Mauritius", "Port Louis", Continent::AFRICA, false),
    Country("Mexico", "Mexico City", Continent::AMERICA, false),
    Country("Moldova", "Chișinău", Continent::EUROPE, true),
    Country("Monaco", "Monaco", Continent::EUROPE, true),
    Country("Mongolia", "Ulaanbaatar", Continent::ASIA, false),
    Country("Montenegro", "Podgorica", Continent::EUROPE, true),
    Country("Mozambique", "Maputo", Continent::AFRICA, false),
    Country("Myanmar", "Naypyidaw", Continent::ASIA, false),
    Country("Namibia", "Windhoek", Continent::AFRICA, false),
    Country("Nepal", "Kathmandu", Continent::ASIA, false),
    Country("Nicaragua", "Managua", Continent::AMERICA, false),
    Country("Niger", "Niamey", Continent::AFRICA, false),
    Country("Nigeria", "Abuja", Continent::AFRICA, false),
    Country("Norway", "Oslo", Continent::EUROPE, true),
    Country("Oman", "Muscat", Continent::ASIA, false),
    Country("Netherlands", "Amsterdam", Continent::EUROPE, true),
    Country("Pakistan", "Islamabad", Continent::ASIA, false),
    Country("Panama", "Panama City", Continent::AMERICA, false),
    Country("Paraguay", "Asunción", Continent::AMERICA, false),
    Country("Peru", "Lima", Continent::AMERICA, false),
    Country("Poland", "Warsaw", Continent::EUROPE, true),
    Country("Portugal", "Lisbon", Continent::EUROPE, true),
    Country("Qatar", "Doha", Continent::ASIA, false),
    Country("North Macedonia", "Skopje", Continent::EUROPE, true),
    Country("Romania", "Bucharest", Continent::EUROPE, true),
    Country("Russia", "Moscow", Continent::EUROPE, true),
    Country("Rwanda", "Kigali", Continent::AFRICA, false),
    Country("Saint Kitts and Nevis", "Basseterre", Continent::AMERICA, false),
    Country("Saint Lucia", "Castries", Continent::AMERICA, false),
    Country("Saint Vincent and the Grenadines", "Kingstown", Continent::AMERICA, false),
    Country("San Marino", "San Marino", Continent::EUROPE, true),
    Country("São Tomé and Príncipe", "São Tomé", Continent::AFRICA, false),
    Country("Senegal", "Dakar", Continent::AFRICA, false),
    Country("Serbia", "Belgrade", Continent::EUROPE, true),
    Country("Seychelles", "Victoria", Continent::AFRICA, false),
    Country("Sierra Leone", "Freetown", Continent::AFRICA, false),
    Country("Singapore", "Singapore", Continent::ASIA, false),
    Country("Slovakia", "Bratislava", Continent::EUROPE, true),
    Country("Slovenia", "Ljubljana", Continent::EUROPE, true),
    Country("Somalia", "Mogadishu", Continent::AFRICA, false),
    Country("Spain", "Madrid", Continent::EUROPE, true),
    Country("Sri Lanka", "Sri Jayawardenepura Kotte", Continent::ASIA, false),
    Country("Sudan", "Khartoum", Continent::AFRICA, false),
    Country("South Sudan", "Juba", Continent::AFRICA, false),
    Country("Suriname", "Paramaribo", Continent::AMERICA, false),
    Country("Sweden", "Stockholm", Continent::EUROPE, true),
    Country("Syria", "Damascus", Continent::ASIA, false),
    Country("Tajikistan", "Dushanbe", Continent::ASIA, false),
    Country("Tanzania", "Dodoma", Continent::AFRICA, false),
    Country("Thailand", "Bangkok", Continent::ASIA, false),
    Country("Timor-Leste", "Dili", Continent::ASIA, false),
    Country("Togo", "Lomé", Continent::AFRICA, false),
    Country("Trinidad and Tobago", "Port of Spain", Continent::AMERICA, false),
    Country("Tunisia", "Tunis", Continent::AFRICA, false),
    Country("Turkey", "Ankara", Continent::ASIA, false),
    Country("Turkmenistan", "Ashgabat", Continent::ASIA, false),
    Country("Uganda", "Kampala", Continent::AFRICA, false),
    Country("Ukraine", "Kyiv", Continent::EUROPE, true),
    Country("Hungary", "Budapest", Continent::EUROPE, true),
    Country("Uruguay", "Montevideo", Continent::AMERICA, false),
    Country("Uzbekistan", "Tashkent", Continent::ASIA, false),
    Country("Vatican City", "Vatican City", Continent::EUROPE, true),
    Country("Venezuela", "Caracas", Continent::AMERICA, false),
    Country("Vietnam", "Hanoi", Continent::ASIA, false),
    Country("Yemen", "Sana'a", Continent::ASIA, false),
    Country("Zambia", "Lusaka", Continent::AFRICA, false),
    Country("Zimbabwe", "Harare", Continent::AFRICA, false),
};

Game::Game(const std::string &playername) : player(playername), currentLevel(0) {
    setLevels();
}

Game &Game::getInstance(const std::string &playername) {
    if (instance == nullptr) {
        instance = new Game(playername);
    }
    return *instance;
}

void Game::destroyInstance() {
    if (instance != nullptr) {
        delete instance;
        instance = nullptr;
    }
}

void Game::setLevels() {
    auto level1 = std::make_unique<LevelwithEuropeanCapitals>();
    for (const auto &country: initialCountries) {
        if (country.getContinent() == Continent::EUROPE && country.isPopular()) {
            level1->addCountry(country.clone());
        }
    }
    levels.push_back(std::move(level1));

    auto level2 = std::make_unique<LevelCountryfromCapital>();
    for (const auto &country: initialCountries) {
        if (country.getContinent() == Continent::EUROPE && country.isPopular()) {
            level2->addCountry(country.clone());
        }
    }
    levels.push_back(std::move(level2));

    auto level3 = std::make_unique<LevelwithContinents>();
    for (const auto &country: initialCountries) {
        level3->addCountry(country.clone());
    }
    levels.push_back(std::move(level3));

    auto level4 = std::make_unique<LevelwithAllCapitals>();
    for (const auto &country: initialCountries) {
        std::vector<std::string> options;
        options.push_back(country.getCapital());

        std::vector<std::string> eligibleCapitals;
        for (const auto &otherCountry: initialCountries) {
            if (otherCountry.getCapital() != country.getCapital()) {
                eligibleCapitals.push_back(otherCountry.getCapital());
            }
        }

        std::shuffle(eligibleCapitals.begin(), eligibleCapitals.end(), std::mt19937(std::random_device()()));
        for (int i = 0; i < 3 && i < eligibleCapitals.size(); ++i) {
            options.push_back(eligibleCapitals[i]);
        }

        std::shuffle(options.begin(), options.end(), std::mt19937(std::random_device()()));

        level4->addCountry(std::make_unique<MultipleChoiceCountry>(country.getName(), country.getCapital(),
                                                                   country.getContinent(), options,
                                                                   country.isPopular()));
    }
    levels.push_back(std::move(level4));
}

void Game::start() {
    std::cout << "Welcome, " << player << "!\n";

    while (currentLevel < levels.size()) {
        player.ResetCurrentScore();
        auto &level = levels[currentLevel];
        level->shuffle();

        std::cout << "\n=== Level " << (currentLevel + 1) << ": " << level->getDescription() << " ===\n";
        std::cout << "You must obtain at least " << level->getMinimum() <<
                " points to move to the next level.\n";

        int CorrectQ = 0;
        for (int i = 0; i < 10; ++i) {
            bool level2 = (currentLevel == 1);
            const Country *currentCountry = level->getRandomCountry();
            if (!currentCountry) {
                std::cout << "There are no more countries available for this level.\n";
                break;
            }

            std::cout << "\n--- Question " << (i + 1) << " ---\n";
            level->displayQuestion(currentCountry);

            if (level2) {
                while (true) {
                    std::string playerAns;
                    std::getline(std::cin, playerAns);

                    if (playerAns == "hint" || playerAns == "Hint") {
                        level->getHint(currentCountry);
                        player.UpdateScore(-1);
                        std::cout << "You lost 1 point! (Current score: "
                                << player.getCurrentScore() << ")\n";
                        continue;
                    }

                    if (level->checkAnswer(currentCountry, playerAns)) {
                        player.UpdateScore(level->getPointsPerAnswer());
                        CorrectQ++;
                        std::cout << "Correct! You now have " << player.getCurrentScore() << " points (Total: "
                                << player.getTotalScore() << ").\n";
                    } else {
                        std::cout << "Wrong! ";
                        level->displayCorrectAnswer(currentCountry);
                    }
                    break;
                }
            } else {
                std::string playerAns;
                std::getline(std::cin, playerAns);

                if (playerAns == "hint" || playerAns == "Hint") {
                    level->getHint(currentCountry);
                    std::cout << "You lost 2 points!\n";
                    std::cout << "Now, write your answer -> ";
                    std::getline(std::cin, playerAns);
                    player.UpdateScore(-2);
                }

                if (level->checkAnswer(currentCountry, playerAns)) {
                    player.UpdateScore(level->getPointsPerAnswer());
                    CorrectQ++;
                    std::cout << "Correct! You now have " << player.getCurrentScore() << " points (Total: "
                            << player.getTotalScore() << ").\n";
                } else {
                    std::cout << "Wrong! ";
                    level->displayCorrectAnswer(currentCountry);
                }
            }
        }

        if (level->isCompleted(player.getCurrentScore())) {
            std::cout << "\nCongratulations! You have completed the level " << (currentLevel + 1) << " with "
                    << player.getCurrentScore() << " points (Total: " << player.getTotalScore() << ").\n";
            currentLevel++;

            if (currentLevel < levels.size()) {
                std::cout << "Go to the next level!\n";
            }
        } else {
            std::cout << "\nYou did not obtain the minimum score required. (" << level->getMinimum()
                    << ") to move to the next level.\n";
            std::cout << "Try again!\n";
            level->shuffle();
        }
    }

    std::cout << "\nGame over. " << player << "\n";
    std::cout << "Total final score: " << player.getTotalScore() << "\n";
    std::cout << "You have completed all the levels!\n";
    ranking.addScore(player.getName(), player.getTotalScore());
    ranking.displayRanking();
}
