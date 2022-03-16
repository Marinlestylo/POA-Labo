/*
-----------------------------------------------------------------------------------
Nom du fichier  : utils.h
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 09.03.2022
Description     : Fichier contenant la déclaration de fonctions utils. Ce dernier
                  défini des fonctions telles que floorMod (inspirée du
                  java) et randomNumber permettant de générer un entier.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO1_UTILS_H
#define LABO1_UTILS_H

#include <cstdlib>
class Utils {
public:
    /**
     * Génère un entier alétoire modulo la valeur passée en paramètre
     * @param mod est le modulo à appliquer sur la valeur aléatoire.
     * @return une valeure entre [0, mod - 1]
     */
    unsigned static randomNumber(unsigned mod);

    /**
     * Effectue un modulo mathématique entre 2 valeurs passées en paramètres. Le
     * résultat ne peut pas être négatif.
     * @param a
     * @param b
     * @return le modulo des deux paramètres
     */
    unsigned static floorMod(long long a, unsigned b);
};
#endif //LABO1_UTILS_H
