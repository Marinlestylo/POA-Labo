//
// Created by Jonathan on 17.03.2022.
//

#include "ship.hpp"
#include <cmath>

Ship::~Ship() {

}

std::ostream &Ship::toStream(std::ostream &os) const {
    return os;
}

Ship::Ship(const std::string &modele, unsigned int weight, unsigned int speed) :
            modele(modele), weight(weight), speed(speed) {

}

// TODO: exception si vitesse trop élevée ?
double Ship::getConsomation(double distance, unsigned speed) const {
    return sqrt(pow(weight, 3)) * log10(weight * speed) * log10(distance + 1);
}

void Ship::setNickname(const std::string& name) {
    nickname = name;
}

unsigned Ship::maxSpeed() const {
    return speed;
}

const std::string &Ship::getModele() {
    return modele;
}

void Ship::setModele(const std::string &modele) {
    Ship::modele = modele;
}

unsigned int Ship::getWeight() {
    return weight;
}

void Ship::setWeight(unsigned int weight) {
    Ship::weight = weight;
}

unsigned int Ship::getSpeed() {
    return speed;
}

void Ship::setSpeed(unsigned int speed) {
    Ship::speed = speed;
}
