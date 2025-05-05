#include "Joc.h"
#include "NivelCapitalaEuropa.h"
#include "NivelTaraDupaCapitala.h"
#include "NivelContinent.h"
#include "NivelCapitalaGlobala.h"
#include "TaraCuVariante.h"
#include <iostream>
#include <algorithm>
#include <random>

std::vector<Tara> Joc::tariInitiale = {
    Tara("Afganistan", "Kabul", Continent::ASIA, false),
    Tara("Africa de Sud", "Pretoria", Continent::AFRICA, false),
    Tara("Albania", "Tirana", Continent::EUROPA, true),
    Tara("Algeria", "Alger", Continent::AFRICA, false),
    Tara("Andorra", "Andorra la Vella", Continent::EUROPA, true),
    Tara("Angola", "Luanda", Continent::AFRICA, false),
    Tara("Antigua si Barbuda", "Saint John's", Continent::AMERICA, false),
    Tara("Arabia Saudita", "Riyadh", Continent::ASIA, false),
    Tara("Argentina", "Buenos Aires", Continent::AMERICA, false),
    Tara("Armenia", "Erevan", Continent::ASIA, false),
    Tara("Austria", "Viena", Continent::EUROPA, true),
    Tara("Azerbaidjan", "Baku", Continent::ASIA, false),
    Tara("Bahamas", "Nassau", Continent::AMERICA, false),
    Tara("Bahrain", "Manama", Continent::ASIA, false),
    Tara("Bangladesh", "Dhaka", Continent::ASIA, false),
    Tara("Barbados", "Bridgetown", Continent::AMERICA, false),
    Tara("Belarus", "Minsk", Continent::EUROPA, true),
    Tara("Belgia", "Bruxelles", Continent::EUROPA, true),
    Tara("Belize", "Belmopan", Continent::AMERICA, false),
    Tara("Benin", "Porto-Novo", Continent::AFRICA, false),
    Tara("Bhutan", "Thimphu", Continent::ASIA, false),
    Tara("Bolivia", "Sucre", Continent::AMERICA, false),
    Tara("Bosnia si Hertegovina", "Sarajevo", Continent::EUROPA, true),
    Tara("Botswana", "Gaborone", Continent::AFRICA, false),
    Tara("Brazilia", "Brasilia", Continent::AMERICA, false),
    Tara("Brunei", "Bandar Seri Begawan", Continent::ASIA, false),
    Tara("Bulgaria", "Sofia", Continent::EUROPA, true),
    Tara("Burkina Faso", "Ouagadougou", Continent::AFRICA, false),
    Tara("Burundi", "Bujumbura", Continent::AFRICA, false),
    Tara("Cambodgia", "Phnom Penh", Continent::ASIA, false),
    Tara("Camerun", "Yaounde", Continent::AFRICA, false),
    Tara("Canada", "Ottawa", Continent::AMERICA, false),
    Tara("Capul Verde", "Praia", Continent::AFRICA, false),
    Tara("Cehia", "Praga", Continent::EUROPA, true),
    Tara("Chile", "Santiago", Continent::AMERICA, false),
    Tara("China", "Beijing", Continent::ASIA, false),
    Tara("Cipru", "Nicosia", Continent::EUROPA, true),
    Tara("Columbia", "Bogota", Continent::AMERICA, false),
    Tara("Comoros", "Moroni", Continent::AFRICA, false),
    Tara("Congo", "Brazzaville", Continent::AFRICA, false),
    Tara("Congo (Republica Democrată)", "Kinshasa", Continent::AFRICA, false),
    Tara("Coreea de Nord", "Pyongyang", Continent::ASIA, false),
    Tara("Coreea de Sud", "Seoul", Continent::ASIA, false),
    Tara("Costa Rica", "San Jose", Continent::AMERICA, false),
    Tara("Croatia", "Zagreb", Continent::EUROPA, true),
    Tara("Cuba", "Havana", Continent::AMERICA, false),
    Tara("Danemarca", "Copenhaga", Continent::EUROPA, true),
    Tara("Djibouti", "Djibouti", Continent::AFRICA, false),
    Tara("Dominica", "Roseau", Continent::AMERICA, false),
    Tara("Ecuador", "Quito", Continent::AMERICA, false),
    Tara("Egipt", "Cairo", Continent::AFRICA, false),
    Tara("El Salvador", "San Salvador", Continent::AMERICA, false),
    Tara("Elvetia", "Berna", Continent::EUROPA, true),
    Tara("Emiratele Arabe Unite", "Abu Dhabi", Continent::ASIA, false),
    Tara("Eritrea", "Asmara", Continent::AFRICA, false),
    Tara("Estonia", "Tallinn", Continent::EUROPA, true),
    Tara("Eswatini", "Mbabane", Continent::AFRICA, false),
    Tara("Etiopia", "Addis Ababa", Continent::AFRICA, false),
    Tara("Filipine", "Manila", Continent::ASIA, false),
    Tara("Finlanda", "Helsinki", Continent::EUROPA, true),
    Tara("Franta", "Paris", Continent::EUROPA, true),
    Tara("Gabon", "Libreville", Continent::AFRICA, false),
    Tara("Gambia", "Banjul", Continent::AFRICA, false),
    Tara("Georgia", "Tbilisi", Continent::ASIA, false),
    Tara("Germania", "Berlin", Continent::EUROPA, true),
    Tara("Ghana", "Accra", Continent::AFRICA, false),
    Tara("Grecia", "Atena", Continent::EUROPA, true),
    Tara("Grenada", "Saint George's", Continent::AMERICA, false),
    Tara("Guatemala", "Guatemala City", Continent::AMERICA, false),
    Tara("Guineea", "Conakry", Continent::AFRICA, false),
    Tara("Guineea-Bissau", "Bissau", Continent::AFRICA, false),
    Tara("Guineea Ecuatoriala", "Malabo", Continent::AFRICA, false),
    Tara("Guyana", "Georgetown", Continent::AMERICA, false),
    Tara("Haiti", "Port-au-Prince", Continent::AMERICA, false),
    Tara("Honduras", "Tegucigalpa", Continent::AMERICA, false),
    Tara("India", "New Delhi", Continent::ASIA, false),
    Tara("Indonezia", "Jakarta", Continent::ASIA, false),
    Tara("Iordania", "Amman", Continent::ASIA, false),
    Tara("Irak", "Baghdad", Continent::ASIA, false),
    Tara("Iran", "Teheran", Continent::ASIA, false),
    Tara("Irlanda", "Dublin", Continent::EUROPA, true),
    Tara("Islanda", "Reykjavik", Continent::EUROPA, true),
    Tara("Israel", "Ierusalim", Continent::ASIA, false),
    Tara("Italia", "Roma", Continent::EUROPA, true),
    Tara("Jamaica", "Kingston", Continent::AMERICA, false),
    Tara("Japonia", "Tokyo", Continent::ASIA, false),
    Tara("Kazahstan", "Nur-Sultan", Continent::ASIA, false),
    Tara("Kenya", "Nairobi", Continent::AFRICA, false),
    Tara("Kuwait", "Kuwait City", Continent::ASIA, false),
    Tara("Kyrgyzstan", "Bishkek", Continent::ASIA, false),
    Tara("Laos", "Vientiane", Continent::ASIA, false),
    Tara("Letonia", "Riga", Continent::EUROPA, true),
    Tara("Liban", "Beirut", Continent::ASIA, false),
    Tara("Lesotho", "Maseru", Continent::AFRICA, false),
    Tara("Liberia", "Monrovia", Continent::AFRICA, false),
    Tara("Libia", "Tripoli", Continent::AFRICA, false),
    Tara("Liechtenstein", "Vaduz", Continent::EUROPA, true),
    Tara("Lituania", "Vilnius", Continent::EUROPA, true),
    Tara("Luxemburg", "Luxemburg", Continent::EUROPA, true),
    Tara("Madagascar", "Antananarivo", Continent::AFRICA, false),
    Tara("Malawi", "Lilongwe", Continent::AFRICA, false),
    Tara("Malaysia", "Kuala Lumpur", Continent::ASIA, false),
    Tara("Maldives", "Male", Continent::ASIA, false),
    Tara("Mali", "Bamako", Continent::AFRICA, false),
    Tara("Malta", "Valletta", Continent::EUROPA, true),
    Tara("Maroc", "Rabat", Continent::AFRICA, false),
    Tara("Mauritania", "Nouakchott", Continent::AFRICA, false),
    Tara("Mauritius", "Port Louis", Continent::AFRICA, false),
    Tara("Mexic", "Mexico City", Continent::AMERICA, false),
    Tara("Moldova", "Chisinau", Continent::EUROPA, true),
    Tara("Monaco", "Monaco", Continent::EUROPA, true),
    Tara("Mongolia", "Ulaanbaatar", Continent::ASIA, false),
    Tara("Muntenegru", "Podgorica", Continent::EUROPA, true),
    Tara("Mozambic", "Maputo", Continent::AFRICA, false),
    Tara("Myanmar", "Naypyidaw", Continent::ASIA, false),
    Tara("Namibia", "Windhoek", Continent::AFRICA, false),
    Tara("Nepal", "Kathmandu", Continent::ASIA, false),
    Tara("Nicaragua", "Managua", Continent::AMERICA, false),
    Tara("Niger", "Niamey", Continent::AFRICA, false),
    Tara("Nigeria", "Abuja", Continent::AFRICA, false),
    Tara("Norvegia", "Oslo", Continent::EUROPA, true),
    Tara("Oman", "Muscat", Continent::ASIA, false),
    Tara("Pakistan", "Islamabad", Continent::ASIA, false),
    Tara("Panama", "Panama City", Continent::AMERICA, false),
    Tara("Paraguay", "Asuncion", Continent::AMERICA, false),
    Tara("Peru", "Lima", Continent::AMERICA, false),
    Tara("Polonia", "Varsovia", Continent::EUROPA, true),
    Tara("Portugalia", "Lisabona", Continent::EUROPA, true),
    Tara("Qatar", "Doha", Continent::ASIA, false),
    Tara("Romania", "Bucuresti", Continent::EUROPA, true),
    Tara("Rusia", "Moscova", Continent::EUROPA, true),
    Tara("Rwanda", "Kigali", Continent::AFRICA, false),
    Tara("San Marino", "San Marino", Continent::EUROPA, true),
    Tara("Sao Tome si Principe", "Sao Tome", Continent::AFRICA, false),
    Tara("Senegal", "Dakar", Continent::AFRICA, false),
    Tara("Serbia", "Belgrad", Continent::EUROPA, true),
    Tara("Seychelles", "Victoria", Continent::AFRICA, false),
    Tara("Sierra Leone", "Freetown", Continent::AFRICA, false),
    Tara("Singapore", "Singapore", Continent::ASIA, false),
    Tara("Siria", "Damasc", Continent::ASIA, false),
    Tara("Slovacia", "Bratislava", Continent::EUROPA, true),
    Tara("Slovenia", "Ljubljana", Continent::EUROPA, true),
    Tara("Somalia", "Mogadishu", Continent::AFRICA, false),
    Tara("Spania", "Madrid", Continent::EUROPA, true),
    Tara("Sri Lanka", "Sri Jayawardenepura Kotte", Continent::ASIA, false),
    Tara("Statele Unite ale Americii", "Washington, D.C.", Continent::AMERICA, false),
    Tara("Sudan", "Khartoum", Continent::AFRICA, false),
    Tara("Sudanul de Sud", "Juba", Continent::AFRICA, false),
    Tara("Suedia", "Stockholm", Continent::EUROPA, true),
    Tara("Surinam", "Paramaribo", Continent::AMERICA, false),
    Tara("Tadjikistan", "Dushanbe", Continent::ASIA, false),
    Tara("Tanzania", "Dodoma", Continent::AFRICA, false),
    Tara("Thailanda", "Bangkok", Continent::ASIA, false),
    Tara("Timorul de Est", "Dili", Continent::ASIA, false),
    Tara("Togo", "Lome", Continent::AFRICA, false),
    Tara("Trinidad si Tobago", "Port of Spain", Continent::AMERICA, false),
    Tara("Tunisia", "Tunis", Continent::AFRICA, false),
    Tara("Turcia", "Ankara", Continent::ASIA, false),
    Tara("Turkmenistan", "Ashgabat", Continent::ASIA, false),
    Tara("Ucraina", "Kiev", Continent::EUROPA, true),
    Tara("Uganda", "Kampala", Continent::AFRICA, false),
    Tara("Ungaria", "Budapesta", Continent::EUROPA, true),
    Tara("Uruguay", "Montevideo", Continent::AMERICA, false),
    Tara("Uzbekistan", "Tashkent", Continent::ASIA, false),
    Tara("Vatican", "Vatican", Continent::EUROPA, true),
    Tara("Venezuela", "Caracas", Continent::AMERICA, false),
    Tara("Vietnam", "Hanoi", Continent::ASIA, false),
    Tara("Yemen", "Sanaa", Continent::ASIA, false),
    Tara("Zambia", "Lusaka", Continent::AFRICA, false),
    Tara("Zimbabwe", "Harare", Continent::AFRICA, false)
};

Joc::Joc(const std::string& numeJucator) : jucator(numeJucator), nivelCurent(0) {
    initializeazaNivele();
}

void Joc::initializeazaNivele() {
    auto nivel1 = std::make_unique<NivelCapitalaEuropa>();
    for (const auto& tara : tariInitiale) {
        if (tara.getContinent() == Continent::EUROPA && tara.estePopulara()) {
            nivel1->adaugaTara(tara.clone());
        }
    }
    nivele.push_back(std::move(nivel1));

    auto nivel2 = std::make_unique<NivelTaraDupaCapitala>();
    for (const auto& tara : tariInitiale) {
        if (tara.getContinent() == Continent::EUROPA && tara.estePopulara()) {
            nivel2->adaugaTara(tara.clone());
        }
    }
    nivele.push_back(std::move(nivel2));

    auto nivel3 = std::make_unique<NivelContinent>();
    for (const auto& tara : tariInitiale) {
        nivel3->adaugaTara(tara.clone());
    }
    nivele.push_back(std::move(nivel3));

    auto nivel4 = std::make_unique<NivelCapitalaGlobala>();
    for (const auto& tara : tariInitiale) {
        std::vector<std::string> variante;
        variante.push_back(tara.getCapitala());

        std::vector<std::string> capitalePosibile;
        for (const auto& altatara : tariInitiale) {
            if (altatara.getCapitala() != tara.getCapitala()) {
                capitalePosibile.push_back(altatara.getCapitala());
            }
        }

        std::shuffle(capitalePosibile.begin(), capitalePosibile.end(), std::mt19937(std::random_device()()));
        for (int i = 0; i < 3 && i < capitalePosibile.size(); ++i) {
            variante.push_back(capitalePosibile[i]);
        }

        std::shuffle(variante.begin(), variante.end(), std::mt19937(std::random_device()()));

        nivel4->adaugaTara(std::make_unique<TaraCuVariante>(tara.getNume(), tara.getCapitala(),
                                                         tara.getContinent(), variante, tara.estePopulara()));
    }
    nivele.push_back(std::move(nivel4));
}

void Joc::start() {
    std::cout << "Bun venit, " << jucator << "!\n";

    while (nivelCurent < nivele.size()) {
        jucator.reseteazaScorCurent();
        auto& nivel = nivele[nivelCurent];
        nivel->amestecaTari();

        std::cout << "\n=== Nivelul " << (nivelCurent + 1) << ": " << nivel->getDescriere() << " ===\n";
        std::cout << "Trebuie sa obtii minim " << nivel->getPunctajMinim() << " puncte pentru a trece la nivelul urmator.\n";

        int intrebariCorecte = 0;
        for (int i = 0; i < 10; ++i) {
            bool Nivel2 = (nivelCurent == 1);
            const Tara* taraCurenta = nivel->getTaraAleatorie();
            if (!taraCurenta) {
                std::cout << "Nu mai sunt tari disponibile pentru acest nivel.\n";
                break;
            }

            std::cout << "\n--- Intrebarea " << (i + 1) << " ---\n";
            nivel->afiseazaIntrebare(taraCurenta);

            if (Nivel2) {
                while (true) {
                    std::string raspunsJucator;
                    std::getline(std::cin, raspunsJucator);

                    if (raspunsJucator == "hint" || raspunsJucator == "Hint") {
                        nivel->getIndiciu(taraCurenta);
                        jucator.actualizeazaScor(-1);
                        std::cout << "Ai pierdut 1 punct! (Scor curent: "
                                  << jucator.getScorCurent() << ")\n";
                        continue;
                    }

                    if (nivel->verificaRaspuns(taraCurenta, raspunsJucator)) {
                        jucator.actualizeazaScor(nivel->getPunctePerRaspuns());
                        intrebariCorecte++;
                        std::cout << "Corect! Ai acum " << jucator.getScorCurent() << " puncte (Total: "
                                  << jucator.getScorTotal() << ").\n";
                    } else {
                        std::cout << "Gresit! ";
                        nivel->afiseazaRaspunsCorect(taraCurenta);
                    }
                    break;
                }
            }
            else{
                std::string raspunsJucator;
                std::getline(std::cin, raspunsJucator);

                if (raspunsJucator == "hint" || raspunsJucator == "Hint") {
                    nivel->getIndiciu(taraCurenta);
                    std::cout << "Ai pierdut 2 puncte!\n";
                    std::cout << "Acum, scrie raspunsul tau -> ";
                    std::getline(std::cin, raspunsJucator);
                    jucator.actualizeazaScor(-2);
                }

                if (nivel->verificaRaspuns(taraCurenta, raspunsJucator)) {
                    jucator.actualizeazaScor(nivel->getPunctePerRaspuns());
                    intrebariCorecte++;
                    std::cout << "Corect! Ai acum " << jucator.getScorCurent() << " puncte (Total: "
                              << jucator.getScorTotal() << ").\n";
                } else {
                    std::cout << "Gresit! ";
                    nivel->afiseazaRaspunsCorect(taraCurenta);
                }
            }
        }

        if (nivel->esteCompletat(jucator.getScorCurent())) {
            std::cout << "\nFelicitari! Ai terminat nivelul " << (nivelCurent + 1) << " cu "
                      << jucator.getScorCurent() << " puncte (Total: " << jucator.getScorTotal() << ").\n";
            nivelCurent++;

            if (nivelCurent < nivele.size()) {
                std::cout << "Treci la nivelul urmator!\n";
            }
        } else {
            std::cout << "\nNu ai obtinut punctajul minim necesar (" << nivel->getPunctajMinim()
                      << ") pentru a trece la nivelul urmator.\n";
            std::cout << "Mai incearca!\n";
            nivel->amestecaTari();
        }
    }

    std::cout << "\nJoc terminat. " << jucator << "\n";
    std::cout << "Scor final total: " << jucator.getScorTotal() << "\n";

    clasament.adaugaScor(jucator.getNume(), jucator.getScorTotal());
    clasament.afiseazaClasament();
    std::cout << "Ai completat toate nivelele!\n";
}