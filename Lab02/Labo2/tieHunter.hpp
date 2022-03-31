//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_TIEHUNTER_HPP
#define LABO1_TIEHUNTER_HPP

#include "ship.hpp"

class TieHunter : public Ship {
public:
    const std::string &getModele() const;

    double getWeight() const;

    unsigned int getSpeed() const;

    TieHunter();

private:
    const static std::string modele;
    const static unsigned speed;
    const static double weight;
};


#endif //LABO1_TIEHUNTER_HPP
