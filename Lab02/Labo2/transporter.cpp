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
#include <iostream>

Transporter::Transporter(
	unsigned int id, double currentLoad, TransporterCharacteristic* characteristic) :
	Ship(id, characteristic) {
	setLoad(currentLoad);
	this->characteristic = characteristic;
}

double Transporter::getLoad() const {
	return currentLoad;
}

void Transporter::setLoad(double load) {
    //std::cout << characteristic->getMaxLoad() << std::endl;
	if (load > characteristic->getMaxLoad() || load < 0) {
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
