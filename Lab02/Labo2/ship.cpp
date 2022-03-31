//
// Created by Jonathan on 17.03.2022.
//

#include "ship.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>

Ship::~Ship() {

}

std::ostream &operator<<(std::ostream &os, const Ship &ship){
    return ship.toStream(os);
}

std::ostream &Ship::toStream(std::ostream &os) const {
    return os << (nickname.empty() ? "" : nickname + " ") << (getModele()) + "\n" << "  weight : "
    << getWeight() << " tons\n  max speed : " << std::setprecision(2) << getSpeed() << " MGLT\n";
}

Ship::Ship(){
}

// TODO: exception si vitesse trop élevée ?
double Ship::getConsomation(double distance, unsigned speed) const {
    return cbrt(getWeight()) * log10(getWeight() * speed) * log10(distance + 1);
}

void Ship::setNickname(const std::string& name) {
    nickname = name;
}



