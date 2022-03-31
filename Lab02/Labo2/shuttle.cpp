//
// Created by Jonathan on 17.03.2022.
//

#include "shuttle.hpp"
const unsigned Shuttle::speed = 100; // L'unité est MGLT
const unsigned Shuttle::weight = 6; // L'unité est tonne
const double Shuttle::maxLoad = 80; // L'unité est tonne
const std::string Shuttle::modele = " [TIE/LN #1]";

Shuttle::Shuttle(double load) : Transporter(load){}

const std::string &Shuttle::getModele() {
    return modele;
}

double Shuttle::getWeight() {
    return weight + getLoad();
}

unsigned int Shuttle::getSpeed() {
    return speed;
}

double Shuttle::getConsomation(double distance, unsigned int speed) const {
    return Ship::getConsomation(distance, speed, weight + Transporter::getLoad());
}

