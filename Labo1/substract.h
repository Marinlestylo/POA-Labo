/*
-----------------------------------------------------------------------------------
Nom du fichier  : substract.h
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Fichier contenant la déclaration de la classe substract. Cette
                  dernière redéfini la méthode "apply" afin de permettre de faire
                  une soustraction entre deux matrices.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO1_SUBSTRACT_H
#define LABO1_SUBSTRACT_H

#include "operation.h"

class Substract : public Operation{
public:
    unsigned apply(unsigned a, unsigned b);
};


#endif //LABO1_SUBSTRACT_H
