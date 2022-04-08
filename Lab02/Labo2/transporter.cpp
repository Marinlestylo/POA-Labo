/*
-----------------------------------------------------------------------------------
Nom du fichier : transporter.cpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Implémentation de la classe Transporter.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "transporter.hpp"
#include <iomanip>

Transporter::Transporter(
	unsigned int id, double currentLoad, CargoCharacteristic* characteristic) :
	Ship(id, characteristic) {

	if (currentLoad >= characteristic->getMaxLoad()) {
		throw std::invalid_argument("Vous tentez de creer un vaisseau avec une trop "
											 "grosse cargaison !");
	}
	this->currentLoad = currentLoad;
}

double Transporter::getLoad() const {
	return currentLoad;
}

void Transporter::setLoad(double load) {
	if (currentLoad >= characteristic->getMaxLoad()) {
		throw std::invalid_argument("Vous tentez de creer un vaisseau avec une trop "
											 "grosse cargaison !");
	}
	currentLoad = load;
}

std::ostream& Transporter::toStream(std::ostream& os) const {
	return Ship::toStream(os) << "  cargo : " << std::setprecision(1)
									  << currentLoad << " tons (max : "
									  << characteristic->getMaxLoad() << ")\n";
}
