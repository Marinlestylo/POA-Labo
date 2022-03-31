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

const unsigned int Dreadnought::speed = 40; // L'unité est MGLT
const unsigned long long Dreadnought::weight = 9000000000; // L'unité est tonne
const std::string Dreadnought::modele = "Super-class Star Destroyer";
const double Dreadnought::maxLoad = 250000;
unsigned int Dreadnought::counter = 0;

Dreadnought::Dreadnought(double load) : Transporter(load, maxLoad) {
	id = ++counter;
}

const std::string& Dreadnought::getModele() const {
	return modele;
}

unsigned int Dreadnought::getId() const {
	return id;
}

double Dreadnought::getWeight() const {
	return weight + getLoad();
}

unsigned int Dreadnought::getSpeed() const {
	return speed;
}

double Dreadnought::getMaxLoad() const {
	return maxLoad;
}
