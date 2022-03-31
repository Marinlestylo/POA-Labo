//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_DREADNOUGHT_HPP
#define LABO1_DREADNOUGHT_HPP

#include "transporter.hpp"

class Dreadnought : public Transporter {
public:
    Dreadnought(double load);
    static const std::string &getModele();

    double getWeight();

    static unsigned int getSpeed();

private:
    const static std::string modele;
    const static unsigned weight, speed;
    const static double maxLoad;

};


#endif //LABO1_DREADNOUGHT_HPP
