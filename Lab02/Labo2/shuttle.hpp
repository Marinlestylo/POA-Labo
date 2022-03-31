//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_SHUTTLE_HPP
#define LABO1_SHUTTLE_HPP

#include "transporter.hpp"

class Shuttle : public Transporter {
public:
    Shuttle(double load);
    static const std::string &getModele();

    double getWeight();

    static unsigned int getSpeed();

protected:
    double getConsomation(double distance, unsigned int speed) const override;

private:
    const static std::string modele;
    const static unsigned weight, speed;
    const static double maxLoad;
};


#endif //LABO1_SHUTTLE_HPP
