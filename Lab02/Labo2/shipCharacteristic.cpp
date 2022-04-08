//
// Created by Jonathan on 08.04.2022.
//

#include "shipCharacteristic.hpp"

ShipCharacteristic::ShipCharacteristic(const std::string& modele, unsigned maxSpeed,
													double weight) : modele(modele), maxSpeed
													(maxSpeed), weight(weight), counter(0) {}

const std::string& ShipCharacteristic::getModele() const {
	return modele;
}

unsigned int ShipCharacteristic::getMaxSpeed() const {
	return maxSpeed;
}

double ShipCharacteristic::getWeight() const {
	return weight;
}

unsigned int ShipCharacteristic::nextId() {
	return counter++;
}
