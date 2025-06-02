#include "Level.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>
#include <cctype>

bool Level::isCloseToCorrect(const std::string &userAnswer, const std::string &correctAnswer,
                             int maxAllowedDifferences) const {
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
    auto removeNonAlpha = [](std::string &str) {
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

    std::vector<std::vector<size_t> > dp(m + 1, std::vector<size_t>(n + 1));

    for (size_t i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (size_t j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    for (size_t i = 1; i <= m; ++i) {
        for (size_t j = 1; j <= n; ++j) {
            if (userLower[i - 1] == correctLower[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({
                               dp[i - 1][j],
                               dp[i][j - 1],
                               dp[i - 1][j - 1]
                           });
            }
        }
    }

    return dp[m][n] <= static_cast<size_t>(maxAllowedDifferences);
}

Level::Level(const std::string &description, int pointsPerAnswer, int minimum)
    : description(description), pointsPerAnswer(pointsPerAnswer), minimum(minimum) {
}

void Level::addCountry(std::unique_ptr<Country> country) {
    countries.push_back(std::move(country));
}

void Level::shuffle() {
    std::mt19937 rng(std::time(0));
    std::shuffle(countries.begin(), countries.end(), rng);
}

const Country *Level::getRandomCountry() {
    std::vector<const Country *> availableCountries;

    for (const auto &country: countries) {
        bool unused = true;
        for (const auto &used: usedCountries) {
            if (*country == *used) {
                unused = false;
                break;
            }
        }

        if (unused) {
            availableCountries.push_back(country.get());
        }
    }

    if (availableCountries.empty()) {
        std::cerr << "Error: All countries in the current level have already been queried.\n";
        return nullptr;
    }

    std::mt19937 rng(std::time(0));
    std::uniform_int_distribution<int> dist(0, availableCountries.size() - 1);
    const Country *randomCountry = availableCountries[dist(rng)];

    usedCountries.push_back(randomCountry->clone());
    return randomCountry;
}

void Level::getHint(const Country * /*tara*/) const {
    std::cout << "Hint: There are no hints available for this level.\n";
}

const std::string &Level::getDescription() const { return description; }
int Level::getPointsPerAnswer() const { return pointsPerAnswer; }
int Level::getMinimum() const { return minimum; }

bool Level::isCompleted(int score) const {
    return score >= minimum;
}
