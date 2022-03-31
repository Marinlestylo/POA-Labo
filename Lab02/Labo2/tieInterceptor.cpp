/*
-----------------------------------------------------------------------------------
Nom du fichier : tieInterceptor.cpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Implémentation de la classe tieInterceptor héritant de Ship.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "tieInterceptor.hpp"

const unsigned TieInterceptor::speed = 110; // L'unité est MGLT
const double TieInterceptor::weight = 5; // L'unité est tonne
const std::string TieInterceptor::modele = "TIE/IN";
unsigned int TieInterceptor::counter = 0;

TieInterceptor::TieInterceptor() {
	id = ++counter;
}

const std::string &TieInterceptor::getModele() const{
    return modele;
}

unsigned int TieInterceptor::getId() const {
	return id;
}

double TieInterceptor::getWeight() const{
    return weight;
}

unsigned int TieInterceptor::getSpeed() const{
    return speed;
}