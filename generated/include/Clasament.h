#ifndef CLASAMENT_H
#define CLASAMENT_H

#include <vector>
#include <string>
#include <utility>
#include <fstream>

class Clasament {
private:
    static const std::string filename;
    std::vector<std::pair<int, std::string>> scores;

public:
    Clasament();
    void adaugaScor(const std::string& player, int scor);
    void afiseazaClasament() const;
    ~Clasament();
};

#endif // CLASAMENT_H