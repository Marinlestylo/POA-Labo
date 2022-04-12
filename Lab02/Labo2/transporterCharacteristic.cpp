#include "transporterCharacteristic.hpp"

TransporterCharacteristic::TransporterCharacteristic(
	const std::string& modele, unsigned maxSpeed, double weight, double maxLoad
) : ShipCharacteristic(modele, maxSpeed, weight), maxLoad(maxLoad) {}

double TransporterCharacteristic::getMaxLoad() const {
	return maxLoad;
}
