#include "Nivel.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>
#include <cctype>

bool Nivel::isCloseToCorrect(const std::string& userAnswer, const std::string& correctAnswer, int maxAllowedDifferences) const {
    std::string userLower = userAnswer;
    std::string correctLower = correctAnswer;
    std::transform(userLower.begin(), userLower.end(), userLower.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    std::transform(correctLower.begin(), correctLower.end(), correctLower.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    if (userLower == correctLower) {
        return true;
    }
    auto removeNonAlpha = [](std::string& str) {
        str.erase(std::remove_if(str.begin(), str.end(),
            [](unsigned char c) { return !std::isalpha(c) && !std::isspace(c); }), str.end());
    };

    removeNonAlpha(userLower);
    removeNonAlpha(correctLower);

    if (userLower == correctLower) {
        return true;
    }

    const size_t m = userLower.size();
    const size_t n = correctLower.size();

    if (std::max(m, n) - std::min(m, n) > static_cast<size_t>(maxAllowedDifferences)) {
        return false;
    }

    std::vector<std::vector<size_t>> dp(m + 1, std::vector<size_t>(n + 1));

    for (size_t i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (size_t j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (userLower[i-1] == correctLower[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + std::min({
                    dp[i-1][j],
                    dp[i][j-1],
                    dp[i-1][j-1]
                });
            }
        }
    }

    return dp[m][n] <= static_cast<size_t>(maxAllowedDifferences);
}

Nivel::Nivel(const std::string& descriere, int punctePerRaspuns, int punctajMinim)
    : descriere(descriere), punctePerRaspuns(punctePerRaspuns), punctajMinim(punctajMinim) {}

void Nivel::adaugaTara(std::unique_ptr<Tara> tara) {
    tari.push_back(std::move(tara));
}

void Nivel::amestecaTari() {
    std::mt19937 rng(std::time(0));
    std::shuffle(tari.begin(), tari.end(), rng);
}

const Tara* Nivel::getTaraAleatorie() {
    std::vector<const Tara*> tariDisponibile;

    for (const auto& tara : tari) {
        bool esteNeintrebata = true;
        for (const auto& taraIntrebata : tariIntrebate) {
            if (*tara == *taraIntrebata) {
                esteNeintrebata = false;
                break;
            }
        }

        if (esteNeintrebata) {
            tariDisponibile.push_back(tara.get());
        }
    }

    if (tariDisponibile.empty()) {
        std::cerr << "Eroare: Toate tarile din nivelul curent au fost deja intrebate.\n";
        return nullptr;
    }

    std::mt19937 rng(std::time(0));
    std::uniform_int_distribution<int> dist(0, tariDisponibile.size() - 1);
    const Tara* taraAleatorie = tariDisponibile[dist(rng)];

    tariIntrebate.push_back(taraAleatorie->clone());
    return taraAleatorie;
}

void Nivel::getIndiciu(const Tara* /*tara*/) const {
    std::cout << "Indiciu: Nu sunt indicii disponibile pentru acest nivel.\n";
}

const std::string& Nivel::getDescriere() const { return descriere; }
int Nivel::getPunctePerRaspuns() const { return punctePerRaspuns; }
int Nivel::getPunctajMinim() const { return punctajMinim; }

bool Nivel::esteCompletat(int scor) const {
    return scor >= punctajMinim;
}