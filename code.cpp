/*
-----------------------------------------------------------------------------------
Nom du fichier  : main.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 10.03.2022
Description     : Fichier principal du programme permettant de tester le bon
                  fonctionnement de la classe Matrix.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <iostream>
#include "matrix.h"

void test();

int main(int argc, char *argv[]) {
	// Décommentez la ligne ci-dessous pour run les tests
	// test();

	// Partie où l'on test que les arguments passés en lignes de commandes sont
	// cohérents
    if(argc != 6){
        throw std::runtime_error("Pas le bon nombre d'argument.");
    }

	 // Si l'un des arguments ne peut pas être transformé en int, le programme crash
	 int nbRow1 = std::stoi(argv[1]);
	 int nbCol1 = std::stoi(argv[2]);
	 int nbRow2 = std::stoi(argv[3]);
	 int nbCol2 = std::stoi(argv[4]);
	 int modulus = std::stoi(argv[5]);

    if(nbRow1 < 0 || nbRow2 < 0 || nbCol1 < 0 || nbCol2 < 0){
        throw std::runtime_error("Les nombres de lignes et de colonnes dovent etre "
											"des entiers positifs ou nuls.");
    }
	 if(modulus < 1){
		 throw std::runtime_error("Le modulo doit etre un entier plus grand que 0.");
	 }
	 // Nous avons cette instruction afin d'éviter que le random soit toujours le
	 // même dans la création des valeurs des matrices.
    srand ((unsigned int) time(NULL));
    Matrix matrix1((unsigned int) nbRow1,(unsigned int) nbCol1,
						 (unsigned int) modulus);
    Matrix matrix2((unsigned int) nbRow2,(unsigned int) nbCol2,
						 (unsigned int) modulus);
    std::cout << "The modulus is " << modulus << std::endl;

    std::cout << "One" << std::endl;
    std::cout << matrix1 << std::endl;

    std::cout << "Two" << std::endl;
    std::cout << matrix2 << std::endl;

    std::cout << "One + Two" << std::endl;
    std::cout << matrix1.addStaticNew(matrix2) << std::endl;

    std::cout << "One - Two" << std::endl;
    std::cout << matrix1.subStaticNew(matrix2) << std::endl;

    std::cout << "One * Two" << std::endl;
    std::cout << matrix1.multStaticNew(matrix2) << std::endl;
    return 0;
}





/**
 * Fonction permettant de tester tous les fonctionnalités d'une Matrix
 * Il est important de noter que certains test sont commentés car il font crash le
 * programme. N'hésitez pas à les décommenter si vous souhaitez les tester.
 */
void test(){
	std::cout << "Creation d'une matrice vide" << std::endl;
	Matrix emptyMatrix(0, 0 ,5);
	std::cout << "Matrice vide :" << std::endl << emptyMatrix << std::endl;

	Matrix noRowMatrix(0, 2 ,5);
	std::cout << "Matrice sans ligne :" << std::endl << noRowMatrix << std::endl;

	Matrix noColMatrix(0, 0 ,5);
	std::cout << "Matrice sans colonne :" << std::endl << noColMatrix << std::endl;

    std::cout << "Creation d'une matrice avec un modulo valant 0" << std::endl;

    try{
        Matrix zeroModuloMat(2, 3 ,0);
    } catch(const std::runtime_error& e){
        std::cout << e.what() << std::endl << std::endl;
    }

	std::cout << "Creation de la matrice \"une\" de taille 2x3 avec 5 comme "
					 "modulo" << std::endl;
	Matrix one(2, 3 ,5);
	std::cout << "Matrice une :" << std::endl << one << std::endl;

	std::cout << "Creation de la matrice \"deux\" de taille 3x3 avec 5 comme "
					 "modulo" << std::endl;
	Matrix two(3, 3 ,5);
	std::cout << "Matrice deux :" << std::endl << two << std::endl;

	std::cout << "Creation de la matrice \"trois\" de taille 2x3 avec 7 comme "
					 "modulo" << std::endl;
	Matrix three(2, 3 ,7);
	std::cout << "Matrice trois :" << std::endl << three << std::endl;

	std::cout << "Creation de la matrice \"quatre\" copiant la matrice \"une\""<<
				 std::endl;
	Matrix four(one);
	std::cout << "Matrice quatre :" << std::endl << four << std::endl;

	std::cout << "Addition des matrices \"une\" et \"deux\"" << std::endl;
	std::cout << "Addition retournant par valeurs" << std::endl <<
	one.addStaticNew(two) << std::endl;

    Matrix* oneAddDynamic = one.addDynamicNew(two);
	std::cout << "Addition retournant par pointeur" << std::endl <<
	*oneAddDynamic << std::endl;
	std::cout << "Addition modifiant la premiere matrice" << std::endl;
	one.addItself(two);
	std::cout << one << std::endl << std::endl;

	std::cout << "Re-initialisation de la matrice \"une\" de taille 2x3 avec 5 comme "
					 "modulo" << std::endl;
	one = Matrix(2, 3 ,5);
	std::cout << "Matrice une :" << std::endl << one << std::endl;
	std::cout << "Matrice deux :" << std::endl << two << std::endl;

	std::cout << "Soustraction des matrices \"une\" et \"deux\" (une - deux)" <<
	std::endl;
	std::cout << "Soustraction retournant par valeurs" << std::endl <<
				 one.subStaticNew(two) << std::endl;

    
	
	
	Matrix* oneSubDynamic = one.subDynamicNew(two);
    std::cout << "Soustraction retournant par pointeur" << std::endl <<
				 *oneSubDynamic << std::endl;
	std::cout << "Soustraction modifiant la premiere matrice" << std::endl;
	one.subItself(two);
	std::cout << one << std::endl << std::endl;

	std::cout << "Re-initialisation de la matrice \"une\" de taille 2x3 avec 5 comme "
					 "modulo" << std::endl;
	one = Matrix(2, 3 ,5);
	std::cout << "Matrice une :" << std::endl << one << std::endl;
	std::cout << "Matrice deux :" << std::endl << two << std::endl;

	std::cout << "Multiplication des matrices \"une\" et \"deux\" (une * deux)" <<
				 std::endl;
	std::cout << "Multiplication retournant par valeurs" << std::endl <<
				 one.multStaticNew(two) << std::endl;

    Matrix* oneMultDynamic = one.multDynamicNew(two);
    std::cout << "Multiplication retournant par pointeur" << std::endl <<
				 *oneMultDynamic << std::endl;
	std::cout << "Multiplication modifiant la premiere matrice" << std::endl;
	one.multItself(two);
	std::cout << one << std::endl << std::endl;

	std::cout << "Re-initialisation de la matrice \"une\" de taille 2x3 avec 5 comme "
					 "modulo" << std::endl;
	one = Matrix(2, 3 ,5);
	std::cout << "Matrice une :" << std::endl << one << std::endl;

    std::cout << "Operation sur des matrices ayant differents modulos" << std::endl;
    std::cout << "\"une\" + \"trois\"" << std::endl;
    try{
        one.addStaticNew(three);
    } catch(const std::invalid_argument& e){
		 std::cout << e.what() << std::endl;
    }
	std::cout << "\"une\" - \"trois\"" << std::endl;
    try{
        one.subDynamicNew(three);
    } catch(const std::invalid_argument& e){
		 std::cout << e.what() << std::endl;
    }
	std::cout << "\"une\" * \"trois\"" << std::endl;
    try{
        one.multItself(three);
    } catch(const std::invalid_argument& e){
        std::cout << e.what() << std::endl;
    }
    delete oneSubDynamic;
    delete oneAddDynamic;
    delete oneMultDynamic;
}
















/*
-----------------------------------------------------------------------------------
Nom du fichier  : matrix.h
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
     * Constructeur de la classe matrix.
     * Une exception (runtime_error) est lancée si le modulo vaut 0
     * @param row taille des lignes
     * @param col taille des colonnes
     * @param mod modules
     */
    Matrix(size_t row, size_t col, unsigned mod);

    /**
     * Constructeur de copie
     * @param matrix matrice à copier
     */
    Matrix(const Matrix &matrix);

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

    size_t row, col;
    unsigned int mod;
    unsigned **values;
};

#endif //LABO1_MATRIX_H
















/*
-----------------------------------------------------------------------------------
Nom du fichier  : matrix.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Fichier contenant l'implémentation de la classe Matrix.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "matrix.h"
#include "add.h"
#include "substract.h"
#include "multiply.h"
#include "utils.h"

Matrix::Matrix(size_t row, size_t col, unsigned mod) : row(row), col(col), mod(mod){
    if(mod == 0){
        throw std::runtime_error("Modulo invalide");
    }
    generateMatrix();
}

Matrix::Matrix(const Matrix &matrix){
    row = matrix.row;
    col = matrix.col;
    mod = matrix.mod;
    values = new unsigned*[row];
    for (size_t i = 0; i < row; ++i) {
        values[i] = new unsigned[col];
    }
    *this = matrix;
}

Matrix::~Matrix() {
    deleteValues();
}



void Matrix::deleteValues() {
    for (size_t i = 0; i < row; ++i) {
        delete[] values[i];
    }
    delete[] values;
}

Matrix &Matrix::operator=(const Matrix &other) {
    if(this != &other){

        changeSizeValues(other.row,other.col);
        this->row = other.row;
        this->col = other.col;
        this->mod = other.mod;
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < col; ++j) {
                values[i][j] = other.getVal(i,j);
            }
        }
    }
    return *this;
}







std::ostream &operator<<(std::ostream &os, const Matrix &matrix){
    for (size_t i = 0; i < matrix.row; ++i) {
        for (size_t j = 0; j < matrix.col; ++j) {
            os << matrix.getVal(i,j) << " ";
        }
        os << std::endl;
    }
    return os;
}

void Matrix::generateMatrix() {
    values = new unsigned*[row];
    for (size_t i = 0; i < row; ++i) {
        values[i] = new unsigned[col];
        for (size_t j = 0; j < col; ++j) {
            values[i][j] = Utils::randomNumber(mod);
        }
    }
}

Matrix& Matrix::addItself(const Matrix &matrix){
    static Add* add = new Add();
    applyOperator(matrix,add);
    return *this;
}

Matrix Matrix::addStaticNew(const Matrix &matrix) const{
    Matrix m(*this);
	 m.addItself(matrix);
    return m;
}

Matrix *Matrix::addDynamicNew(const Matrix &matrix) const{
    Matrix* m = new Matrix(*this);
    try{
        m->addItself(matrix);
    } catch(const std::invalid_argument& e){
        delete m;
        throw;
    }
    return m;
}

Matrix& Matrix::subItself(const Matrix &matrix) {
    static Substract* sub = new Substract();
    applyOperator(matrix,sub);
    return *this;
}
Matrix Matrix::subStaticNew(const Matrix &matrix) const{
    Matrix m(*this);
	 m.subItself(matrix);
    return m;
}

Matrix *Matrix::subDynamicNew(const Matrix &matrix) const{
    Matrix* m = new Matrix(*this);
    try{
        m->subItself(matrix);
    } catch(const std::invalid_argument& e){
        delete m;
        throw;
    }
    return m;
}
Matrix& Matrix::multItself(const Matrix &matrix){
    static Multiply* mult = new Multiply();
    applyOperator(matrix,mult);
    return *this;
}

Matrix Matrix::multStaticNew(const Matrix &matrix) const{
    Matrix m(*this);
	 m.multItself(matrix);
    return m;
}

Matrix *Matrix::multDynamicNew(const Matrix &matrix) const{
    Matrix* m = new Matrix(*this);
    try{
        m->multItself(matrix);
    } catch(const std::invalid_argument& e){
        delete m;
        throw;
    }
    return m;
}

void Matrix::changeSizeValues(size_t row, size_t col){
    if(this->row == row && this->col == col) {
        return;
    }
        unsigned** newValues = new unsigned*[row];
    for (size_t i = 0; i < row; ++i) {
        newValues[i] = new unsigned[col];
    }
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            newValues[i][j] = this->getVal(i,j);
        }
    }
    deleteValues();
    this->row = row;
    this->col = col;
    values = newValues;
}

Matrix* Matrix::applyOperator(const Matrix &matrix, Operation* op){
    if(this->mod != matrix.mod){
        throw std::invalid_argument("Les modulos des deux matrices ne sont pas "
                                    "egaux");
    }
    changeSizeValues(std::max(this->row, matrix.row),std::max(this->col,matrix.col));

    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < this->col; ++j) {
            values[i][j] = Utils::floorMod(op->apply(this->getVal(i,j), matrix
            .getVal(i,j)),mod);
        }
    }
    return this;
}

unsigned Matrix::getVal(size_t row, size_t col) const{
    if(row >= this->row || col >= this->col){
        return 0;
    }
    return values[row][col];
}










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
    virtual long long apply(unsigned a, unsigned b) = 0;
};


#endif //LABO1_OPERATION_H


/*
-----------------------------------------------------------------------------------
Nom du fichier  : add.h
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Fichier contenant la déclaration de la classe add. Cette
                  dernière redéfini la méthode "apply" afin de permettre de faire
                  une addition entre deux matrices.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#ifndef LABO1_ADD_H
#define LABO1_ADD_H

#include "operation.h"


class Add : public Operation{
public:
    long long apply(unsigned a, unsigned b);
};


#endif //LABO1_ADD_H


/*
-----------------------------------------------------------------------------------
Nom du fichier  : add.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Fichier contenant l'implémentation de la classe add.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "add.h"
long long Add::apply(unsigned a, unsigned b){
    return (long long) a + (long long) b;
}


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
    long long apply(unsigned a, unsigned b);
};


#endif //LABO1_SUBSTRACT_H


/*
-----------------------------------------------------------------------------------
Nom du fichier  : substract.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Fichier contenant l'implémentation de la classe substract.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "substract.h"
long long Substract::apply(unsigned a, unsigned b){
    return (long long) a - (long long) b;
}

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
    long long apply(unsigned a, unsigned b);
};



#endif //LABO1_MULTIPLY_H




/*
-----------------------------------------------------------------------------------
Nom du fichier  : multiply.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Fichier contenant l'implémentation de la classe multiply.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "multiply.h"
long long Multiply::apply(unsigned a, unsigned b){
    return (long long) a * (long long) b;
}

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
