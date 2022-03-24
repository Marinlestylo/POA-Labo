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

Ship::Ship(){
}

// TODO: exception si vitesse trop élevée ?
double Ship::getConsomation(double distance, unsigned speed, unsigned weight) const {
    return sqrt(pow(weight, 3)) * log10(weight * speed) * log10(distance + 1);
}

void Ship::setNickname(const std::string& name) {
    nickname = name;
}



