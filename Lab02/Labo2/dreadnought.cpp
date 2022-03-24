//
// Created by Jonathan on 17.03.2022.
//

#include "dreadnought.hpp"
const unsigned Dreadnought::speed = 100; // L'unité est MGLT
const unsigned Dreadnought::weight = 6; // L'unité est tonne
const std::string Dreadnought::modele = " [TIE/LN #1]";

Dreadnought::Dreadnought(double load) : Transporter(load){}

const std::string &Dreadnought::getModele() {
    return modele;
}

unsigned int Dreadnought::getWeight() {
    return weight;
}

unsigned int Dreadnought::getSpeed() {
    return speed;
}