//
// Created by Jonathan on 17.03.2022.
//

#include "tieHunter.hpp"
const unsigned TieHunter::speed = 100; // L'unité est MGLT
const unsigned TieHunter::weight = 6; // L'unité est tonne
const std::string TieHunter::modele = " [TIE/LN #1]";

const std::string &TieHunter::getModele() {
    return modele;
}

unsigned int TieHunter::getWeight() {
    return weight;
}

unsigned int TieHunter::getSpeed() {
    return speed;
}


