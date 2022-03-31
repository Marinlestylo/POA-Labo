//
// Created by Jonathan on 17.03.2022.
//

#include "transporter.hpp"
Transporter::Transporter(double currentLoad) : currentLoad(currentLoad){}

double Transporter::getLoad() const {
    return currentLoad;
}

void Transporter::setLoad(double load) {
    currentLoad = load;
}