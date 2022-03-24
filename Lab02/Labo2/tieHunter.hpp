//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_TIEHUNTER_HPP
#define LABO1_TIEHUNTER_HPP

#include "ship.hpp"

class tieHunter : public Ship {
public:
    static const std::string &getModele();

    static unsigned int getWeight();

    static unsigned int getSpeed();

private:
    const static std::string modele;
    const static unsigned weight, speed;
};


#endif //LABO1_TIEHUNTER_HPP
