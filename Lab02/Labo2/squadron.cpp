#include "Squadron.hpp"
#include <math.h>

using namespace std;

Squadron::Squadron(const string& name) {
    initVariables(name, nullptr, nullptr);
}

Squadron::Squadron(const Squadron &other) {
    initVariables(other.name,other.leader,other.listHead->valeur);
    Maillon *toCopy = other.listHead->suivant;
    while (toCopy != nullptr) {
        addShipFromSquadron(*toCopy->valeur);
        toCopy = toCopy->suivant;
    }
}

Squadron::~Squadron() {
    Maillon *tmp = listHead;
    Maillon *toDelete = listHead;
    while (tmp != nullptr) {
        tmp = tmp->suivant;
        delete toDelete;
        toDelete = tmp;
    }
}

void Squadron::initVariables(const string& newName, Ship *newLeader,Ship* newHead) {
    this->name = newName;
    this->leader = newLeader;
    this->listHead = newHead == nullptr ? nullptr : new Maillon{newHead,nullptr};
    this->listTail = listHead;

}

Squadron& Squadron::operator=(const Squadron& other){
    if(this == &other){
        return *this;
    }
    leader = other.leader;
    listHead = new Maillon{other.listHead->valeur, nullptr};
    Maillon *toCopy = other.listHead;
    while (toCopy != nullptr) {
        addShipFromSquadron(*toCopy->valeur);
        toCopy = toCopy->suivant;
    }
    return *this;
}

void Squadron::setLeader(Ship &newLeader) {
    addShipFromSquadron(newLeader);
    this->leader = &newLeader;
}

/**
 *
 * @param ship
 * @return
 */
Squadron Squadron::addShip(Ship &ship) const {
    Squadron newSquadron(*this);
    newSquadron.addShipFromSquadron(ship);
    return newSquadron;
}

Squadron Squadron::removeShip(const Ship &ship) const {
    Squadron newSquadron(*this);
    newSquadron.removeShipFromSquadron(ship);
    return newSquadron;
}

Squadron &Squadron::addShipFromSquadron(Ship &ship) {
    Maillon *tmp = listHead;
    while (tmp != nullptr) {
        if (tmp->valeur == &ship) {
            return *this;
        }
        tmp = tmp->suivant;
    }

    Maillon *newMaillon = new Maillon{&ship, nullptr};
    if (listHead == nullptr) {
        listHead = newMaillon;
    } else {
        listTail->suivant = newMaillon;
    }
    listTail = newMaillon;
    return *this;
}

Squadron &Squadron::removeShipFromSquadron(const Ship &ship) {
    Maillon *toRemove = listHead;
    Maillon *tmp = listHead;
    while (toRemove != nullptr) {
        if (toRemove->valeur == &ship) {
            if (toRemove == listHead) {
                listHead = toRemove->suivant;
            } else if (toRemove == listTail) {
                listTail = tmp;
            } else {
                tmp->suivant = toRemove->suivant;
            }
            delete toRemove;
            break;
        }
        tmp = toRemove;
        toRemove = toRemove->suivant;
    }
    return *this;
}

const Ship &Squadron::getShip(size_t i) const {
    Maillon *tmp = listHead;
    size_t counter = 0;
    while (counter++ != i && tmp->suivant != nullptr) {
        tmp = tmp->suivant;
    }
    if (counter == i + 1) {
        return *tmp->valeur;
    }
    throw out_of_range("Le Squadron ne contient pas ce vaisseau");
}

void Squadron::squadronInfos(unsigned &speed, double &weight) const {
    speed = 0;
    weight = 0;

    Maillon *tmp = listHead;
    while (tmp != nullptr) {
        if(speed > tmp->valeur->getMaxSpeed() || speed == 0){
            speed = tmp->valeur->getMaxSpeed();
        }
        weight += tmp->valeur->getWeight();
        tmp = tmp->suivant;
    }
}

Squadron &Squadron::operator+=(Ship &ship) {
    return addShipFromSquadron(ship);
}

Squadron &Squadron::operator-=(const Ship &ship) {
    return removeShipFromSquadron(ship);
}

const Ship &Squadron::operator[](size_t i) const {
    return getShip(i);
}


Squadron operator+(const Squadron &squadron, Ship &ship) {
    return squadron.addShip(ship);
}

Squadron operator-(const Squadron &squadron, const Ship &ship) {
    return squadron.removeShip(ship);
}

double Squadron::getConsumption(double distance, unsigned int speed) const {
    unsigned maxSpeed;
    double totalWeight;
    squadronInfos(maxSpeed, totalWeight);
    if(speed > maxSpeed || distance < 0){
        throw std::invalid_argument("Ce squadron ne peut pas atteindre une telle "
                                    "vitesse ou une telle distance");
    }

    Maillon* ship = this->listHead;
    double consumption = 0;

    while(ship != nullptr){
        consumption += ship->valeur->getConsumption(distance, speed);
        ship = ship->suivant;
    }
    return consumption;
}

ostream &operator<<(ostream &os, const Squadron &squadron) {
    unsigned maxSpeed;
    double squadronWeight;
    squadron.squadronInfos(maxSpeed, squadronWeight);

    os << "Squadron: " << squadron.name << endl;
    os << " max speed: " << maxSpeed << " MGLT" << endl;
    os << " total weight: " << squadronWeight << " tons" << endl;

    os << endl << "-- Leader" << endl;
    Squadron::Maillon *member = squadron.listHead;
    if (squadron.leader != nullptr)
        os << *squadron.leader << endl;

    os << "-- Members" << endl;
    while (member != nullptr) {
        if (member->valeur != squadron.leader)
            os << *member->valeur << endl;
        member = member->suivant;
    }
    return os;
}

