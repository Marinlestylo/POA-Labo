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

const unsigned Shuttle::speed = 54; // L'unité est MGLT
const double Shuttle::weight = 360; // L'unité est tonne
const double Shuttle::maxLoad = 80; // L'unité est tonne
const std::string Shuttle::modele = "Lambda-class shuttle";
unsigned int Shuttle::counter = 0;

Shuttle::Shuttle(double load) : Transporter(++counter, load, maxLoad){}

const std::string& Shuttle::getModele() const {
	return modele;
}

double Shuttle::getWeight() const {
	return weight + getLoad();
}

unsigned int Shuttle::getSpeed() const {
	return speed;
}

double Shuttle::getMaxLoad() const {
	return maxLoad;
}
