//
// Created by Jonathan on 17.03.2022.
//

#include "tieHunter.hpp"
const unsigned tieHunter::speed = 100; // L'unité est MGLT
const unsigned tieHunter::weight = 6; // L'unité est tonne
const std::string tieHunter::modele = " [TIE/LN #1]";

const std::string &tieHunter::getModele() {
    return modele;
}

unsigned int tieHunter::getWeight() {
    return weight;
}

unsigned int tieHunter::getSpeed() {
    return speed;
}


