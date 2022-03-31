//
// Created by Jonathan on 17.03.2022.
//

#include "Squadron.hpp"
#include <math.h>

Squadron::Squadron(std::string name){
    this->name = name;
    leader = nullptr;
    listHead = nullptr;
}

Squadron::Squadron(const Squadron& other){
    listHead = other.listHead;
    leader = other.leader;
}

void Squadron::setLeader(Ship& leader){
    if(this->leader != nullptr){
        Ship& s = *this->leader;
        *this += s;
    }
    this->leader = &leader;
}

Squadron Squadron::addShip(const Ship& ship) const{
    Squadron newSquadron(*this);
    newSquadron.addShipFromSquadron(ship);
    return newSquadron;
}

Squadron Squadron::removeShip(const Ship& ship) const{
    Squadron newSquadron(*this);
    newSquadron.removeShipFromSquadron(ship);
    return newSquadron;
}

Squadron& Squadron::addShipFromSquadron(const Ship& ship){
    if(!this->containShip((Ship &)ship))
        listHead = new Maillon{(Ship&)ship,listHead};
    return *this;
}

Squadron& Squadron::removeShipFromSquadron(const Ship& ship){
    if(listHead == nullptr)
        return *this;

    Maillon* tmp = listHead;
    Maillon* m = listHead;
    while(tmp != nullptr){
        if(&(tmp->valeur) == &ship){
            if(tmp == listHead){
                listHead = tmp->suivant;
            }else{
                m->suivant = tmp->suivant;
            }
            delete tmp;
            break;
        }
        m = tmp;
        tmp = tmp->suivant;
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
        return tmp->valeur;
    }
    throw std::runtime_error("Le Squadron ne contient pas ce vaisseau");
}

unsigned Squadron::getMaxSpeed() const{
    unsigned speed = 0;
    Maillon* tmp = listHead;
    while (tmp != nullptr){
        speed = std::min(speed, tmp->valeur.maxSpeed());
        tmp = tmp->suivant;
    }
}

Squadron& Squadron::operator+=(const Ship &ship){
    addShipFromSquadron(ship);
}
Squadron& Squadron::operator-=(const Ship &ship){
    removeShipFromSquadron(ship);
}

bool Squadron::containShip(const Ship& ship) const{
    if(listHead == nullptr)
        return false;
    Maillon* tmp = listHead;
    bool contain = false;
    do{
        if(&(tmp->valeur) == &ship){
            return true;
        }
    }while (tmp->suivant != nullptr);

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
    size_t i = 0;
    Ship* leader = squadron.leader;
    os << "-- Leader"
    Squadron::Maillon* member = squadron.listHead;
    if (leader != nullptr)
        os << squadron.leader;
    while(member->suivant != nullptr){
        os << member->valeur << std::endl;
    }
    return os;
}