//
// Created by Jonathan on 08.04.2022.
//

#include "cargoCharacteristic.hpp"

CargoCharacteristic::CargoCharacteristic(
	const std::string& modele, unsigned maxSpeed, double weight, double maxLoad
) : ShipCharacteristic(modele, maxSpeed, weight), maxLoad(maxLoad) {}

double CargoCharacteristic::getMaxLoad() const {
	return maxLoad;
}
