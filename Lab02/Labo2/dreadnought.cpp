#include "dreadnought.hpp"

TransporterCharacteristic Dreadnought::characteristic(
	"Super-class Star Destroyer", 40, 9000000000, 250000
);

Dreadnought::Dreadnought(double load) : Transporter(
	load, &characteristic
){}