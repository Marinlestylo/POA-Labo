//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_SQUADRON_HPP
#define LABO1_SQUADRON_HPP

#include "ship.hpp"

class Squadron;

std::ostream &operator<<(std::ostream &os, Squadron &squadron);

Squadron operator+(const Squadron &squadron, Ship &ship);

Squadron operator-(const Squadron &squadron, Ship &ship);

class Squadron {
    struct Maillon {
        Ship &valeur;
        Maillon *suivant;
    };

    friend std::ostream &operator<<(std::ostream &os, Squadron &squadron);

    friend Squadron operator+(const Squadron &squadron, Ship &ship);

    friend Squadron operator-(const Squadron &squadron, const Ship &ship);

public:
    Squadron(std::string name);

    Squadron(const Squadron &other);

    ~Squadron();

    void setLeader(Ship &ship);

    Squadron &addShipFromSquadron(Ship &ship);

    Squadron &removeShipFromSquadron(const Ship &ship);

    const Ship &getShip(size_t i) const;

    Ship &getShip(size_t i);

    void squadronInfos(unsigned& speed, double& weight) const;

    Squadron removeShip(const Ship &ship) const;

    Squadron addShip(Ship &ship) const;

    Squadron &operator+=(Ship &ship);

    Squadron &operator-=(const Ship &ship);

    Ship &operator[](size_t i);
    const Ship &operator[](size_t i) const;

private:
    Ship *leader;
    Maillon *listHead;
    Maillon *listTail;
    std::string name;
};


#endif //LABO1_SQUADRON_HPP
