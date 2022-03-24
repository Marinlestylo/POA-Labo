//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_TRANSPORTER_HPP
#define LABO1_TRANSPORTER_HPP

#include "ship.hpp"

class Transporter : public Ship {
public:
    Transporter(double load);
private:
double load;
public:
    double getLoad() const;
};


#endif //LABO1_TRANSPORTER_HPP
