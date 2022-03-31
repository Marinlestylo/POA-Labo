/*
-----------------------------------------------------------------------------------
Nom du fichier : ship.cpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Implémentation de la classe Ship.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "ship.hpp"
#include <cmath>
#include <iomanip>

Ship::Ship() {}

// TODO: Destructeur par défaut ?
Ship::~Ship() {}

std::ostream& operator<<(std::ostream& os, const Ship& ship) {
	return ship.toStream(os);
}

std::ostream& Ship::toStream(std::ostream& os) const {
	return os << (nickname.empty() ? "" : (nickname + " ")) << (getIdentity()) + "\n"
				 << "  weight : "
				 << std::fixed << std::setprecision(2) << getWeight()
				 << " tons\n  max speed : " << getSpeed() << " MGLT\n";
}

// TODO: exception si vitesse trop élevée ?
double Ship::getConsomation(double distance, unsigned speed) const {
	return cbrt(getWeight()) * log10(getWeight() * speed) * log10(distance + 1);
}

void Ship::setNickname(const std::string& name) {
	nickname = name;
}

//TODO: demander si y'a moyen de faire + clean
std::string Ship::getIdentity() const {
	return "[" + getModele() + " #" + std::to_string(getId()) + "]";
}


