#include "ship.hpp"
#include <cmath>
#include <iomanip>

Ship::Ship(ShipCharacteristic *characteristic) :
        characteristic(characteristic) {
    id = characteristic->nextId();
}

std::ostream &operator<<(std::ostream &os, const Ship &ship) {
    return ship.toStream(os);
}

std::ostream &Ship::toStream(std::ostream &os) const {
    return os << (nickname.empty() ? "" : (nickname + " ")) << (getIdentity()) + "\n"
              << "  weight : "
              << std::fixed << std::setprecision(2) << getWeight()
              << " tons\n  max speed : " << characteristic->getMaxSpeed()
              << " MGLT";
}

double Ship::getConsumption(double distance, unsigned speed) const {
    if (speed > characteristic->getMaxSpeed() || distance < 0) {
        throw std::invalid_argument("La vitesse ou la distance n'est pas "
                                    "atteignable");
    }
    return cbrt(getWeight()) / 2 * log10(getWeight() * speed) * log10(distance + 1);
}

void Ship::setNickname(const std::string &name) {
    nickname = name;
}

std::string Ship::getIdentity() const {
    return "[" + characteristic->getModele() + " #" + std::to_string
            (id) + "]";
}

double Ship::getWeight() const {
    return characteristic->getWeight();
}

unsigned int Ship::getMaxSpeed() const {
    return characteristic->getMaxSpeed();
}



