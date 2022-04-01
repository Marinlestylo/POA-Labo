//
// Created by Jonathan on 17.03.2022.
//

#include "Squadron.hpp"
#include <math.h>

Squadron::Squadron(std::string name){
    this->name = name;
    leader = nullptr;
    listHead = nullptr;
    listTail = nullptr;
}

Squadron::Squadron(const Squadron& other){
    listHead = other.listHead;
    leader = other.leader;
    listTail = other.listTail;
}

void Squadron::setLeader(Ship& leader){
    if(this->leader != nullptr){
        const Ship& s = *this->leader;
        addShipFromSquadron(*this->leader);
    }
    this->leader = &leader;
}

Squadron Squadron::addShip(Ship& ship) const{
    Squadron newSquadron(*this);
    newSquadron.addShipFromSquadron(ship);
    return newSquadron;
}

Squadron Squadron::removeShip(const Ship& ship) const{
    Squadron newSquadron(*this);
    newSquadron.removeShipFromSquadron(ship);
    return newSquadron;
}

Squadron& Squadron::addShipFromSquadron(Ship& ship){
    if(this->containShip(ship))
        return *this;

    Maillon* newMaillon = new Maillon{ship, nullptr};
    if(listHead == nullptr){
        listHead = newMaillon;
    } else{
        listTail->suivant = newMaillon;
    }
    listTail = newMaillon;
    return *this;
}

Squadron& Squadron::removeShipFromSquadron(const Ship& ship){
    if(listHead == nullptr)
        return *this;

    Maillon* toRemove = listHead;
    Maillon* tmp = listHead;
    while(toRemove != nullptr){
        if(&(toRemove->valeur) == &ship){
            if(toRemove == listHead){
                listHead = toRemove->suivant;
            } else if(toRemove == listTail){
                listTail = tmp;
            }else{
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

Ship& Squadron::getShip(size_t i) const{
    if(listHead == nullptr)
        throw std::runtime_error("Le Squadron ne contient pas de vaisseau");
    Maillon * tmp = listHead;
    size_t counter = 0;
    while(tmp->suivant != nullptr && counter++ != i){
        tmp = tmp->suivant;
    }
    if(counter == i+1){
        return (Ship&)*tmp;
    }
    throw std::runtime_error("Le Squadron ne contient pas ce vaisseau");
}

unsigned Squadron::getMaxSpeed() const{
    unsigned speed = 0;
    Maillon* tmp = listHead;
    while (tmp != nullptr){
        speed = std::min(speed, tmp->valeur.getSpeed());
        tmp = tmp->suivant;
    }
}

Squadron& Squadron::operator+=(Ship &ship){
    addShipFromSquadron(ship);
}
Squadron& Squadron::operator-=(const Ship &ship){
    removeShipFromSquadron(ship);
}

bool Squadron::containShip(const Ship& ship) const{
    if(listHead == nullptr)
        return false;
    Maillon* tmp = listHead;
    while (tmp != nullptr){
        if(&(tmp->valeur) == &ship){
            return true;
        }
        tmp = tmp->suivant;
    }
    return false;
}

Ship& Squadron::operator[](size_t i) const{
    return getShip(i);
}

Squadron operator+(const Squadron &squadron, Ship &ship){
    return squadron.addShip(ship);
}

Squadron operator-(const Squadron &squadron, const Ship &ship){
    return squadron.removeShip(ship);
}

std::ostream &operator<<(std::ostream &os, Squadron &squadron){
    const Ship* leader = squadron.leader;
    os << "\n-- Leader\n";
    Squadron::Maillon* member = squadron.listHead;
    if (leader != nullptr)
        os << *squadron.leader;
    os << "\n-- Member\n";
    while(member != nullptr){
        if(&member->valeur != leader)
        os << member->valeur << std::endl;
        member = member->suivant;
    }
    return os;
}