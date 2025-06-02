#include "Ranking.h"
#include "Errors.h"
#include <iostream>
#include <algorithm>
#include <cstdint>

const std::string Ranking::filename = "clasament.txt";

Ranking::Ranking() {
    std::ifstream in(filename);
    if (!in.good()) {
        return;
    }

    uint32_t size;
    if (!(in >> size)) {
        throw ScoreFileReadError();
    }

    scores.resize(size);
    for (auto &[score, player]: scores) {
        in >> std::ws;
        std::getline(in, player, ' ');
        if (!(in >> score)) {
            throw ScoreFileFormatError();
        }
    }
}

void Ranking::addScore(const std::string &player, int score) {
    scores.emplace_back(score, player);
    std::sort(scores.begin(), scores.end(), std::greater<std::pair<int, std::string> >());
    if (scores.size() > 100) {
        scores.resize(100);
    }
}

void Ranking::displayRanking() const {
    std::cout << "\n=== RANKING TOP 10 ===\n";
    int count = std::min(10, static_cast<int>(scores.size()));
    for (int i = 0; i < count; i++) {
        std::cout << (i + 1) << ". " << scores[i].second << " - "
                << scores[i].first << " points\n";
    }
}

Ranking::~Ranking() {
    std::ofstream out(filename);
    if (!out) {
        return;
    }

    out << scores.size() << "\n";
    for (const auto &[score, player]: scores) {
        out << player << " " << score << "\n";
    }
}
