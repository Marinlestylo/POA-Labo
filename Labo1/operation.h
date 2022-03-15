/*
-----------------------------------------------------------------------------------
Nom du fichier  : operation.h
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Fichier contenant la déclaration de la classe opération ainsi
                  que de sa méthode "apply" qui permettra d'effectuer une opération
                  sur des matrices. La méthode "apply" devra être redéfinie dans
                  les sous-classes.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO1_OPERATION_H
#define LABO1_OPERATION_H


class Operation {
public:
    virtual long long apply(long long a, long long b) = 0;
};


#endif //LABO1_OPERATION_H
