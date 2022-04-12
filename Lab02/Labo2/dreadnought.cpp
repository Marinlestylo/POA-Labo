/*
-----------------------------------------------------------------------------------
Nom du fichier : dreadnought.cpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Implémentation de la classe dreadnought.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "dreadnought.hpp"

/*const unsigned int Dreadnought::speed = 40; // L'unité est MGLT
const unsigned long long Dreadnought::weight = 9000000000; // L'unité est tonne
const std::string Dreadnought::modele = "Super-class Star Destroyer";
const double Dreadnought::maxLoad = 250000;
unsigned int Dreadnought::counter = 0;*/

TransporterCharacteristic Dreadnought::characteristic(
	"Super-class Star Destroyer", 40, 9000000000, 250000
);

Dreadnought::Dreadnought(double load) : Transporter(
	characteristic.nextId(), load, &characteristic
), load(load) {}


double Dreadnought::getWeight() const {
	return characteristic.getWeight() + load;
}