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
    test();
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
    }
	std::cout << "\"une\" - \"trois\"" << std::endl;
    try{
        one.subDynamicNew(three);
    } catch(const std::invalid_argument& e){
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
