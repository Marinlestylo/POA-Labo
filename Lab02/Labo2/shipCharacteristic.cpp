#include "shipCharacteristic.hpp"

ShipCharacteristic::ShipCharacteristic(const std::string &modele, unsigned maxSpeed,
                                       double weight) : modele(modele), maxSpeed
        (maxSpeed), weight(weight), counter(1) {}

const std::string &ShipCharacteristic::getModele() const {
    return modele;
}

unsigned int ShipCharacteristic::getMaxSpeed() const {
    return maxSpeed;
}

double ShipCharacteristic::getWeight() const {
    return weight;
}

unsigned int ShipCharacteristic::nextId() {
    return counter++;
}
