#include "transporter.hpp"
#include <iomanip>
#include <iostream>

Transporter::Transporter(
	double currentLoad, TransporterCharacteristic* characteristic) :
	Ship(characteristic) {
    this->characteristic = characteristic;
    setLoad(currentLoad);
}

double Transporter::getLoad() const {
	return currentLoad;
}

void Transporter::setLoad(double load) {
	if (load > this->characteristic->getMaxLoad() || load < 0) {
		throw std::invalid_argument("Vous tentez de mettre une cargaison trop lourde"
											 " dans ce vaisseau !");
	}
	currentLoad = load;
}

std::ostream& Transporter::toStream(std::ostream& os) const {
	return Ship::toStream(os) << "  cargo : " << std::setprecision(1)
									  << currentLoad << " tons (max : "
									  << characteristic->getMaxLoad() << ")\n";
}

double Transporter::getWeight() const {
    return characteristic->getWeight() + currentLoad;
}
