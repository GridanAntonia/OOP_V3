#include "Clasament.h"
#include "Erori.h"
#include <iostream>
#include <algorithm>
#include <cstdint>

const std::string Clasament::filename = "clasament.txt";

Clasament::Clasament() {
    std::ifstream in(filename);
    if (!in.good()) {
          return;
//        throw ScoreFileOpenError();
    }
    
    uint32_t size;
    if (!(in >> size)) {
        throw ScoreFileReadError();
    }
    
    scores.resize(size);
    for (auto& [score, player] : scores) {
        in >> std::ws;
        std::getline(in, player, ' ');
        if (!(in >> score)) {
            throw ScoreFileFormatError();
        }
    }
}

void Clasament::adaugaScor(const std::string& player, int scor) {
    scores.emplace_back(scor, player);
    std::sort(scores.begin(), scores.end(), std::greater<std::pair<int, std::string>>());
    if (scores.size() > 100) {
        scores.resize(100);
    }
}

void Clasament::afiseazaClasament() const {
    std::cout << "\n=== CLASAMENT TOP 10 ===\n";
    int count = std::min(10, static_cast<int>(scores.size()));
    for (int i = 0; i < count; i++) {
        std::cout << (i+1) << ". " << scores[i].second << " - " 
                  << scores[i].first << " puncte\n";
    }
}

Clasament::~Clasament() {
    std::ofstream out(filename);
    if (!out) {
        return;
    }
    
    out << scores.size() << "\n";
    for (const auto& [score, player] : scores) {
        out << player << " " << score << "\n";
    }
}