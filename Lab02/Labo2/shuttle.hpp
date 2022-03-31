//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_SHUTTLE_HPP
#define LABO1_SHUTTLE_HPP

#include "transporter.hpp"

class Shuttle : public Transporter {
public:
    Shuttle(double load);
    const std::string &getModele() const;

    double getWeight() const;

    unsigned int getSpeed() const;


private:
    const static std::string modele;
    const static unsigned weight, speed;
    const static double maxLoad;
};


#endif //LABO1_SHUTTLE_HPP
