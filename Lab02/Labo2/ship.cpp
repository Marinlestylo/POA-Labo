//
// Created by Jonathan on 17.03.2022.
//

#include "ship.hpp"

Ship::~Ship() {

}

std::ostream &Ship::toStream(std::ostream &os) const {
    return os;
}

Ship::Ship(const std::string &modele, unsigned int weight, unsigned int speed) :
            modele(modele), weigth(weight), speed(speed) {

}

unsigned Ship::maxSpeed() const {
    return speed;
}
