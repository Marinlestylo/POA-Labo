//
// Created by Jonathan on 17.03.2022.
//

#include "shuttle.hpp"
const unsigned Shuttle::speed = 100; // L'unité est MGLT
const unsigned Shuttle::weight = 6; // L'unité est tonne
const std::string Shuttle::modele = " [TIE/LN #1]";

Shuttle::Shuttle(double load) : load(load) {

}

const std::string &Shuttle::getModele() {
    return modele;
}

unsigned int Shuttle::getWeight() {
    return weight;
}

unsigned int Shuttle::getSpeed() {
    return speed;
}

