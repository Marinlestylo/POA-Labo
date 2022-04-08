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

ShipCharacteristic TieInterceptor::characteristic(
	"TIE/IN", 110, 5
);

TieInterceptor::TieInterceptor() : Ship(characteristic.nextId(), &characteristic) {}