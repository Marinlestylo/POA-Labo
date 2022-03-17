/*
-----------------------------------------------------------------------------------
Nom du fichier  : multiply.hpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Fichier contenant la déclaration de la classe multiply. Cette
                  dernière redéfini la méthode "apply" afin de permettre de faire
                  une multiplication composante par composante entre deux matrices.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#ifndef LABO1_MULTIPLY_HPP
#define LABO1_MULTIPLY_HPP

#include "operation.hpp"

class Multiply : public Operation{
public:
    long long apply(unsigned a, unsigned b);
};



#endif //LABO1_MULTIPLY_HPP
