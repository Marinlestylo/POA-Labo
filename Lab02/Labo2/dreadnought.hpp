//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_DREADNOUGHT_HPP
#define LABO1_DREADNOUGHT_HPP

#include "transporter.hpp"

class Dreadnought : public Transporter {
public:
    Dreadnought(double load);
    const std::string &getModele() const;

    double getWeight() const;

    unsigned int getSpeed() const;

    double getMaxLoad() const;

private:
    const static std::string modele;
    const static unsigned weight, speed;
    const static double maxLoad;

};


#endif //LABO1_DREADNOUGHT_HPP
