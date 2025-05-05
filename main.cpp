#include <iostream>
#include <array>
#include<Clasament.h>
#include<Erori.h>
#include<Joc.h>
#include <Jucator.h>
#include <Nivel.h>
#include<NivelContinent.h>
#include<NivelCapitalaEuropa.h>
#include<NivelCapitalaGlobala.h>
#include<NivelTaraDupaCapitala.h>
#include<Scor.h>
#include<Tara.h>
#include<TaraCuVariante.h>


int main() {
    std::string numeJucator;
    std::cout << "Introdu numele tau: ";
    std::getline(std::cin, numeJucator);

    Joc joc(numeJucator);
    joc.start();
    return 0;
}
