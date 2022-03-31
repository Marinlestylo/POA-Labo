//
// Created by Jonathan on 17.03.2022.
//

#include "tieHunter.hpp"
const unsigned TieHunter::speed = 100; // L'unité est MGLT
const double TieHunter::weight = 6; // L'unité est tonne
const std::string TieHunter::modele = " [TIE/LN #1]";

const std::string& TieHunter::getModele() const{
    return modele;
}

double TieHunter::getWeight() const{
    return weight;
}

unsigned int TieHunter::getSpeed() const{
    return speed;
}

TieHunter::TieHunter() {}


