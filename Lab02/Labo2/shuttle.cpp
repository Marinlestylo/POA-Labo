/*
-----------------------------------------------------------------------------------
Nom du fichier : shuttle.cpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Implémentation de la classe shuttle.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "shuttle.hpp"

CargoCharacteristic Shuttle::characteristic(
	"Lambda-class shuttle", 54, 360, 80
);

Shuttle::Shuttle(double load) : Transporter(
	characteristic.nextId(), load, &characteristic
), load(load) {}


double Shuttle::getWeight() const {
	return characteristic.getWeight() + load;
}
