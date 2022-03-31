//
// Created by Jonathan on 17.03.2022.
//

#include "shuttle.hpp"
const unsigned Shuttle::speed = 100; // L'unité est MGLT
const unsigned Shuttle::weight = 6; // L'unité est tonne
const double Shuttle::maxLoad = 80; // L'unité est tonne
const std::string Shuttle::modele = " [ Lambda-class shuttle #1]";

Shuttle::Shuttle(double load) : Transporter(load){}

const std::string &Shuttle::getModele() const{
    return modele;
}

double Shuttle::getWeight() const{
    return weight + getLoad();
}

unsigned int Shuttle::getSpeed() const{
    return speed;
}

double Shuttle::getMaxLoad() const{
    return maxLoad;
}

