/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 17.03.2022
Description     : Fichier principal du programme permettant de tester le bon
                  fonctionnement de la classe Squadron.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <iomanip>
#include <iostream>
#include "tieHunter.hpp"
#include "shuttle.hpp"
#include "squadron.hpp"

int main() {
    tieHunter blackLeader;
    blackLeader.setNickname("Black leader");
    tieHunter blackTwo;
    Shuttle shuttle(23.4); // 23.4 tonnes de marchandises
    Squadron squad("Black Squadron");
    squad += blackLeader;
    squad += blackTwo;
    squad += shuttle;
    squad.setLeader(blackLeader);
    std::cout << squad << std::endl;
}