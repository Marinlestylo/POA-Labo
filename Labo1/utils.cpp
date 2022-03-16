/*
-----------------------------------------------------------------------------------
Nom du fichier  : utils.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 09.03.2022
Description     : Fichier contenant l'implémentation de fonctions utilitaires.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "utils.h"

unsigned Utils::randomNumber(unsigned mod) {
    return (unsigned)rand() % mod;
}


unsigned Utils::floorMod(long long a, unsigned b) {
    a %= (long long)b;
    return unsigned (a < 0 ? a + (long long)b : a);
}
