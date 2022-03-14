/*
-----------------------------------------------------------------------------------
Nom du fichier  : multiply.h
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Fichier contenant la déclaration de la classe multiply. Cette
                  dernière redéfini la méthode "apply" afin de permettre de faire
                  une multiplication composante par composante entre deux matrices.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#ifndef LABO1_MULTIPLY_H
#define LABO1_MULTIPLY_H

#include "operation.h"

class Multiply : public Operation{
public:
    unsigned apply(unsigned a, unsigned b);
};



#endif //LABO1_MULTIPLY_H
