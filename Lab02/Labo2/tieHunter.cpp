/*
-----------------------------------------------------------------------------------
Nom du fichier : tieHunter.cpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Implémentation de la classe tieHunter héritant de Ship.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "tieHunter.hpp"

const unsigned TieHunter::speed = 100; // L'unité est MGLT
const double TieHunter::weight = 6; // L'unité est tonne
const std::string TieHunter::modele = "TIE/LN";
unsigned int TieHunter::counter = 0;

TieHunter::TieHunter() {
	id = ++counter;
}

const std::string& TieHunter::getModele() const {
	return modele;
}

unsigned int TieHunter::getId() const {
	return id;
}

double TieHunter::getWeight() const {
	return weight;
}

unsigned int TieHunter::getSpeed() const {
	return speed;
}
