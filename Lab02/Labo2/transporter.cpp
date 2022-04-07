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

// TODO: ESSAYER DE MODIF CA, il a dit que c'était un peu deg
Transporter::Transporter(unsigned int id, double currentLoad, double maxLoad) : Ship(id){
	if (currentLoad >= maxLoad) {
		throw std::invalid_argument("Vous tentez de creer un vaisseau avec une trop "
											 "grosse cargaison !");
	}
	this->currentLoad = currentLoad;
}

double Transporter::getLoad() const {
	return currentLoad;
}

void Transporter::setLoad(double load) {
	currentLoad = load;
}

std::ostream& Transporter::toStream(std::ostream& os) const {
	return Ship::toStream(os) << "  cargo : " << std::setprecision(1)
									  << getLoad() << " tons (max : "
									  << getMaxLoad() << ")\n";
}
