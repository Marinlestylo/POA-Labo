#include <iostream>
#include <sstream>
#include "boat.hpp"

const std::string Boat::RIVER =
        "==============================================================================";

Boat::Boat(Bank *current) : Container("Bateau", std::list<Person *>()),
                            currentBank(current) {}


void Boat::showContainer() const {
    std::stringstream ss;
    if (currentBank->getName() == "droite")
        ss << std::endl << RIVER << std::endl;

    ss << Container::getName() << " : " <<  "< " << Container::getPeopleNames() <<
    " >";
    if (currentBank->getName() == "gauche")
        ss << std::endl << RIVER << std::endl;
    std::cout << ss.str();
}

void Boat::moveBoat(Bank *bank) {
    bool hasDriver = false;
    for (Person *p: *Container::getPeople()) {
        if (p->canDrive()) {
            hasDriver = true;
        }
    }
    if (!hasDriver) {
        std::cout << "Il n'y a pas de conducteur dans le bateau" << std::endl;
        return;
    }
    currentBank = bank;

}

Bank *Boat::getBank() const {
    return currentBank;
}

bool Boat::isDockedOnthisBank(Bank *bank) const {
    return bank == currentBank;
}

bool Boat::isFull() const {
    return Container::getPeople()->size() == 2;
}