#include "dreadnought.hpp"

TransporterCharacteristic Dreadnought::characteristic(
	"Super-class Star Destroyer", 40, 9000000000, 250000
);

Dreadnought::Dreadnought(double load) : Transporter(
	characteristic.nextId(), load, &characteristic
), load(load) {}


double Dreadnought::getWeight() const {
	return characteristic.getWeight() + load;
}