/*
-----------------------------------------------------------------------------------
Nom du fichier  : matrix.h
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 10.03.2022
Description     :
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO1_MATRIX_H
#define LABO1_MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "operation.h"

class Matrix;

std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

class Matrix {
public:
    /**
     * Constructeur de la classe matrix
     * @param row taille des lignes
     * @param col taille des colonnes
     * @param mod modules
     */
    Matrix(unsigned int row, unsigned int col, unsigned mod);
    /**
     * Constructeur de copie
     * @param matrix matrice à copier
     */
    Matrix(const Matrix &matrix);

    ~Matrix();

    /**
     * Surcharge de l'opérateur d'affectation
     * @param other Matrice à copier
     * @return la matrice après l'affectation
     */
    Matrix &operator=(const Matrix &other);

    /**
     * Surcharge de l'opérateur de flux afin de pouvoir afficher une matrice
     * @param os opérateur de flux
     * @param matrix matrice à afficher
     * @return opérateur de flux utilisé
     */
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

    /**
     * Addition entre deux matrices, modifie la matrice depuis laquelle la fonction
     * est appelée.
     * @param matrix matrice à additionner
     * @return une référance sur la matrice modifiée après l'addition
     */
    Matrix& addItself(const Matrix &matrix);

    /**
     * Addition entre deux matrices, crée une nouvelle matrice résultant du calcul
     * @param matrix matrice à additionner
     * @return la matrice modifiée après l'addition
     */
    Matrix addStaticNew(const Matrix &matrix);

    /**
     * Addition entre deux matrices, crée une nouvelle matrice résultant du calcul
     * @param matrix matrice à additionner
     * @return un pointeur sur la matrice modifiée après l'addition
     */
    Matrix* addDynamicNew(const Matrix &matrix);

    /**
     * Soustraction entre deux matrices, modifie la matrice depuis laquelle la
     * fonction est appelée.
     * @param matrix matrice à soustraire
     * @return une référance sur la matrice modifiée après la soustraction
     */
    Matrix& subItself(const Matrix &matrix);
    /**
     * Soustraction entre deux matrices, crée une nouvelle matrice résultant du
     * calcul
     * @param matrix matrice à soustraire
     * @return la matrice modifiée après la soustraction
     */
    Matrix subStaticNew(const Matrix &matrix);
    /**
     * Soustraction entre deux matrices, crée une nouvelle matrice résultant du
     * calcul
     * @param matrix matrice à soustraire
     * @return un pointeur sur la matrice modifiée après la soustraction
     */
    Matrix* subDynamicNew(const Matrix &matrix);

    /**
     * Multiplication entre deux matrices, modifie la matrice depuis laquelle la
     * fonction est appelée.
     * @param matrix matrice à soustraire
     * @return une référance sur la matrice modifiée après la soustraction
     */
    Matrix& multItself(const Matrix &matrix);
    /**
     * Multiplication entre deux matrices, crée une nouvelle matrice résultant du
     * calcul
     * @param matrix matrice à multiplier
     * @return la matrice modifiée après la multiplication
     */
    Matrix multStaticNew(const Matrix &matrix);
    /**
     * Multiplication entre deux matrices, crée une nouvelle matrice résultant du
     * calcul
     * @param matrix matrice à multiplier
     * @return un pointeur sur la matrice modifiée après la multiplication
     */
    Matrix* multDynamicNew(const Matrix &matrix);

    /**
     * Getter du module
     * @return le module de la matrice
     */
    unsigned int getMod() const;

    /**
     * Getter du nombre de lignes
     * @return le nombre de lignes
     */
	 unsigned int getRow() const;

    /**
     * Getter du nombre de colonnes
     * @return le nombre de colonnes
     */
	 unsigned int getCol() const;

    /**
     * Retourne un élément de la matrice
     * @param row le numéro de la ligne
     * @param col le numéro de la colonne
     * @return l'élément se trouvant aux index passés en paramètre
     */
    unsigned getVal(unsigned int row, unsigned int col) const;

private:
    /**
     * Génère une matrice possédant des valeurs aléatoires
     */
    void generateMatrix();

    /**
     * Change la taille de la matrice
     * @param row nouveau nombre de ligne
     * @param col nouveau nombre de colonne
     */
    void changeSizeValues(unsigned int row, unsigned int col);

    /**
     * Désalloue et détruit le tableau de tableau possédant les valeurs de la matrice
     */
    void deleteValues();

    /**
     * Génère un nombre aléatoire
     */
    unsigned randomNumber();

    /**
     * Applique une opération passée en paramètre à tous les éléments de deux
     * matrices.
     * @param matrix
     * @param op
     * @return
     */
    Matrix* applyOperator(const Matrix &matrix, Operation *op);

	 unsigned int row, col, mod;
    unsigned** values;
};
#endif //LABO1_MATRIX_H
