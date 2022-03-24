//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_TIEINTERCEPTOR_HPP
#define LABO1_TIEINTERCEPTOR_HPP


#include "ship.hpp"

class TieInterceptor : public Ship {
public:
    static const std::string &getModele();

    static unsigned int getWeight();

    static unsigned int getSpeed();

private:
    const static std::string modele;
    const static unsigned weight, speed;

};


#endif //LABO1_TIEINTERCEPTOR_HPP
