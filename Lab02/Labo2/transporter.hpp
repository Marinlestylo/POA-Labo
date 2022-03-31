//
// Created by Jonathan on 17.03.2022.
//

#ifndef LABO1_TRANSPORTER_HPP
#define LABO1_TRANSPORTER_HPP

#include "ship.hpp"

class Transporter : public Ship {
public:
    double getLoad() const;
    void setLoad(double load);

protected:
    Transporter(double currentLoad);
private:
    double currentLoad;
};


#endif //LABO1_TRANSPORTER_HPP
