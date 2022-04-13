#include "squadron.hpp"
#include <cmath>

using namespace std;

Squadron::Squadron(const string &name) {
    initVariables(name, nullptr, nullptr);
}

Squadron::Squadron(const Squadron &other) {
    initVariables(other.name, other.leader, other.listHead->value);
    Link *toCopy = other.listHead->next;
    while (toCopy != nullptr) {
        addShipToSquadron(*toCopy->value);
        toCopy = toCopy->next;
    }
}

Squadron::~Squadron() {
    Link *tmp = listHead;
    Link *toDelete = listHead;
    while (tmp != nullptr) {
        tmp = tmp->next;
        delete toDelete;
        toDelete = tmp;
    }
}

void Squadron::initVariables(const string &newName, Ship *newLeader, Ship *newHead) {
    this->name = newName;
    this->leader = newLeader;
    this->listHead = newHead == nullptr ? nullptr : new Link{newHead, nullptr};
}

Squadron &Squadron::operator=(const Squadron &other) {
    if (this == &other) {
        return *this;
    }
    Link *toDelete = listHead;
    Link *tmp = toDelete->next;

    while (toDelete != nullptr) {
        delete toDelete;
        toDelete = tmp;
        if (tmp != nullptr) {
            tmp = tmp->next;
        }
    }
    initVariables(other.name, other.leader, other.listHead->value);
    tmp = other.listHead->next;
    while (tmp != nullptr) {
        addShipToSquadron(*tmp->value);
        tmp = tmp->next;
    }
    return *this;
}

void Squadron::setLeader(Ship &newLeader) {
    addShipToSquadron(newLeader);
    this->leader = &newLeader;
}

Squadron Squadron::addShip(Ship &ship) const {
    Squadron newSquadron(*this);
    return newSquadron.addShipToSquadron(ship);;
}

Squadron Squadron::removeShip(const Ship &ship) const {
    Squadron newSquadron(*this);
    return newSquadron.removeShipFromSquadron(ship);
}

Squadron &Squadron::addShipToSquadron(Ship &ship) {
    Link *tmp = listHead;
    Link *newMaillon = new Link{&ship, nullptr};
    if (tmp == nullptr) {
        listHead = newMaillon;
        return *this;
    }
    while (tmp != nullptr) {
        if (tmp->value == &ship) {
            return *this;
        }
        if (tmp->next == nullptr) {
            break;
        }
        tmp = tmp->next;
    }
    tmp->next = newMaillon;
    return *this;
}

Squadron &Squadron::removeShipFromSquadron(const Ship &ship) {
    Link *toRemove = listHead;
    Link *tmp = listHead;
    while (toRemove != nullptr) {
        if (toRemove->value == &ship) {
            if (toRemove == listHead) {
                listHead = toRemove->next;
            } else {
                tmp->next = toRemove->next;
            }
            delete toRemove;
            break;
        }
        tmp = toRemove;
        toRemove = toRemove->next;
    }
    return *this;
}

const Ship &Squadron::getShip(size_t index) const {
    Link *tmp = listHead;
    size_t counter = 0;
    while (counter++ != index && tmp->next != nullptr) {
        tmp = tmp->next;
    }
    if (counter == index + 1) {
        return *tmp->value;
    }
    throw out_of_range("Le Squadron ne contient pas de vaisseau à cet index");
}

void Squadron::squadronInfos(unsigned &speed, double &weight) const {
    speed = 0;
    weight = 0;

    Link *tmp = listHead;
    while (tmp != nullptr) {
        if (speed > tmp->value->getMaxSpeed() || speed == 0) {
            speed = tmp->value->getMaxSpeed();
        }
        weight += tmp->value->getWeight();
        tmp = tmp->next;
    }
}

Squadron &Squadron::operator+=(Ship &ship) {
    return addShipToSquadron(ship);
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
    if (speed > maxSpeed || distance < 0) {
        throw std::invalid_argument("Ce squadron ne peut pas atteindre une telle "
                                    "vitesse ou une telle distance");
    }

    Link *ship = this->listHead;
    double consumption = 0;

    while (ship != nullptr) {
        consumption += ship->value->getConsumption(distance, speed);
        ship = ship->next;
    }
    return consumption;
}

ostream &operator<<(ostream &os, const Squadron &squadron) {
    return squadron.toStream(os);
}

std::ostream &Squadron::toStream(std::ostream &os) const{
    unsigned maxSpeed;
    double squadronWeight;
    squadronInfos(maxSpeed, squadronWeight);

    os << "Squadron: " << name << endl;
    os << " max speed: " << maxSpeed << " MGLT" << endl;
    os << " total weight: " << squadronWeight << " tons" << endl;

    os << endl << "-- Leader" << endl;
    Squadron::Link *member = listHead;
    if (leader != nullptr)
        os << *leader << endl << endl;

    os << "-- Members" << endl;
    while (member != nullptr) {
        if (member->value != leader)
            os << *member->value << endl << endl;
        member = member->next;
    }
    return os;
}


