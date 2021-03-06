/*
-----------------------------------------------------------------------------------
Nom du fichier  : matrix.hpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Classe permettant de modéliser des matrices de tailles diverses.
                  Il est possible de leur appliquer plusieurs opérations:
                  (L'addition, la soustraction ainsi que la multiplication).
                  Chaque opération peut se faire de 3 manières. Soit en modifiant
                  la matrice sur laquelle l'opération est invoquée. Soit en
                  renvoyant par valeur une nouvelle matrice allouée statiquement.
                  Soit en retournant un pointeur sur un nouvelle matrice allouée
                  dynamiquement.
                  Il est également possible d'afficher une matrice dans la console
                  via l'opérateur d'écriture de flux "<<".
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO1_MATRIX_HPP
#define LABO1_MATRIX_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "operation.hpp"

class Matrix;

std::ostream &operator<<(std::ostream &os, const Matrix &matrix);

class Matrix {
public:
    /**
     * Constructeur de la classe matrix.
     * Une exception (runtime_error) est lancée si le modulo vaut 0
     * @param row taille des lignes
     * @param col taille des colonnes
     * @param mod modules
     */
    Matrix(size_t row, size_t col, unsigned mod);

    /**
     * Constructeur de copie
     * @param other matrice à copier
     */
    Matrix(const Matrix &other);

    /**
     * Destructeur de la classe Matrix
     */
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
     * Cette méthode peut throw une exception invalid_argument.
     * @param matrix matrice à additionner
     * @return une référance sur la matrice modifiée après l'addition
     */
    Matrix &addItself(const Matrix &matrix);

    /**
     * Addition entre deux matrices, crée une nouvelle matrice résultant du calcul.
     * Cette méthode peut throw une exception invalid_argument.
     * @param matrix matrice à additionner
     * @return la matrice modifiée après l'addition
     */
    Matrix addStaticNew(const Matrix &matrix) const;

    /**
     * Addition entre deux matrices, crée une nouvelle matrice résultant du calcul.
     * Cette méthode peut throw une exception invalid_argument.
     * @param matrix matrice à additionner
     * @return un pointeur sur la matrice modifiée après l'addition
     */
    Matrix *addDynamicNew(const Matrix &matrix) const;

    /**
     * Soustraction entre deux matrices, modifie la matrice depuis laquelle la
     * fonction est appelée.
     * Cette méthode peut throw une exception invalid_argument.
     * @param matrix matrice à soustraire
     * @return une référance sur la matrice modifiée après la soustraction
     */
    Matrix &subItself(const Matrix &matrix);

    /**
     * Soustraction entre deux matrices, crée une nouvelle matrice résultant du
     * calcul.
     * Cette méthode peut throw une exception invalid_argument.
     * @param matrix matrice à soustraire
     * @return la matrice modifiée après la soustraction
     */
    Matrix subStaticNew(const Matrix &matrix) const;

    /**
     * Soustraction entre deux matrices, crée une nouvelle matrice résultant du
     * calcul.
     * Cette méthode peut throw une exception invalid_argument.
     * @param matrix matrice à soustraire
     * @return un pointeur sur la matrice modifiée après la soustraction
     */
    Matrix *subDynamicNew(const Matrix &matrix) const;

    /**
     * Multiplication entre deux matrices, modifie la matrice depuis laquelle la
     * fonction est appelée.
     * Cette méthode peut throw une exception invalid_argument.
     * @param matrix matrice à soustraire
     * @return une référance sur la matrice modifiée après la soustraction
     */
    Matrix &multItself(const Matrix &matrix);

    /**
     * Multiplication entre deux matrices, crée une nouvelle matrice résultant du
     * calcul.
     * Cette méthode peut throw une exception invalid_argument.
     * @param matrix matrice à multiplier
     * @return la matrice modifiée après la multiplication
     */
    Matrix multStaticNew(const Matrix &matrix) const;

    /**
     * Multiplication entre deux matrices, crée une nouvelle matrice résultant du
     * calcul.
     * Cette méthode peut throw une exception invalid_argument.
     * @param matrix matrice à multiplier
     * @return un pointeur sur la matrice modifiée après la multiplication
     */
    Matrix *multDynamicNew(const Matrix &matrix) const;

private:
    /**
     * Génère une matrice possédant des valeurs aléatoires
     */
    void generateMatrix();


    /**
     * Retourne un élément de la matrice, renvoi 0 si les index sont en dehors de
     * la matrice
     * @param row le numéro de la ligne
     * @param col le numéro de la colonne
     * @return l'élément se trouvant aux index passés en paramètre
     */
    unsigned getVal(size_t row, size_t col) const;

    /**
     * Change la taille de la matrice
     * @param row nouveau nombre de ligne
     * @param col nouveau nombre de colonne
     */
    void changeSizeValues(size_t row, size_t col);

    /**
     * Désalloue et détruit le tableau de tableau possédant les valeurs de la matrice
     */
    void deleteValues();

    /**
     * Applique une opération passée en paramètre à tous les éléments de deux
     * matrices.
     * @param matrix
     * @param op
     * @return
     */
    Matrix *applyOperator(const Matrix &matrix, Operation *op);

    /**
      * Remplace les valuers de la matrice actuelle par les valeurs de la matrice
      * passée en paramètre.
      * @param other
      */
    void replaceValues(const Matrix &other);

    size_t row, col;
    unsigned int mod;
    unsigned **values;
};

#endif //LABO1_MATRIX_HPP
