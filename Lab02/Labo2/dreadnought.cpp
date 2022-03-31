//
// Created by Jonathan on 17.03.2022.
//

#include "dreadnought.hpp"
const unsigned Dreadnought::speed = 100; // L'unité est MGLT
const unsigned Dreadnought::weight = 6; // L'unité est tonne
const std::string Dreadnought::modele = " [Super-class Star Destroyer #1]";
const double Dreadnought::maxLoad = 250000;

Dreadnought::Dreadnought(double load) : Transporter(load){}

const std::string &Dreadnought::getModele() const{
    return modele;
}

double Dreadnought::getWeight() const{
    return weight + getLoad();
}

unsigned int Dreadnought::getSpeed() const{
    return speed;
}

double Dreadnought::getMaxLoad() const{
    return maxLoad;
}