//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_TIEINTERCEPTOR_HPP
#define LABO1_TIEINTERCEPTOR_HPP


#include "ship.hpp"

class TieInterceptor : public Ship {
public:
    const std::string &getModele() const;

    double getWeight() const;

    unsigned int getSpeed() const;

private:
    const static std::string modele;
    const static unsigned weight, speed;

};


#endif //LABO1_TIEINTERCEPTOR_HPP
