//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_TIEHUNTER_HPP
#define LABO1_TIEHUNTER_HPP

#include "ship.hpp"

class tieHunter : public Ship {
public:
    tieHunter();
private:
    tieHunter(const std::string& modele = "[TIE/LN #1]", unsigned weight = 6, unsigned speed = 100);
};


#endif //LABO1_TIEHUNTER_HPP
