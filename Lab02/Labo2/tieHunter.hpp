/*
-----------------------------------------------------------------------------------
Nom du fichier : tieHunter.hpp
Auteur(s)      : Alexandre Jaquier et Jonathan Friedli
Date creation  : 17.03.2022
Description    : Déclaration de la classe tieHunter héritant de Ship.
Compilateur    : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO1_TIEHUNTER_HPP
#define LABO1_TIEHUNTER_HPP

#include "ship.hpp"

class TieHunter : public Ship {
public:

	TieHunter();

private:
	static ShipCharacteristic characteristic;
};


#endif //LABO1_TIEHUNTER_HPP
