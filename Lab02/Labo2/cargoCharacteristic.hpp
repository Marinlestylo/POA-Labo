//
// Created by Jonathan on 08.04.2022.
//

#ifndef LABO1_CARGOCHARACTERISTIC_HPP
#define LABO1_CARGOCHARACTERISTIC_HPP


#include "shipCharacteristic.hpp"

class CargoCharacteristic : public ShipCharacteristic{
public:
	explicit CargoCharacteristic(const std::string& modele, unsigned maxSpeed,
										  double weight, double maxLoad);

	double getMaxLoad() const;
private:
	double maxLoad;
};


#endif //LABO1_CARGOCHARACTERISTIC_HPP
