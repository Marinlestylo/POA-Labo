//
// Created by Jonathan on 17.03.2022.
//

#include "transporter.hpp"
Transporter::Transporter(double load) : load(load){}

double Transporter::getLoad() const {
    return load;
}
