/*
-----------------------------------------------------------------------------------
Nom du fichier  : add.h
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Implémentations des fonctions Utils.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "utils.h"
#include <cstdlib>

unsigned randomNumber(unsigned mod) {
	return (unsigned)rand() % mod;
}

unsigned floorMod(long long a,unsigned b){
	a %= (long long)b;
	return unsigned (a < 0 ? a + (long long)b : a);
}
