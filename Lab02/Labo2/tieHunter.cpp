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

ShipCharacteristic TieHunter::characteristic(
	"TIE/LN", 100, 6
);

TieHunter::TieHunter() : Ship(characteristic.nextId(), &characteristic) {}