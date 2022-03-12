#include <iostream>
#include "matrix.h"

int main(int argc, char *argv[]) {
    if(argc != 6){
        throw std::runtime_error("Pas le bon nombre d'argument.");
    }
	 int nbRow1 = std::stoi(argv[1]);
	 int nbCol1 = std::stoi(argv[2]);
	 int nbRow2 = std::stoi(argv[3]);
	 int nbCol2 = std::stoi(argv[4]);
	 int modulus = std::stoi(argv[5]);
    if(nbRow1 < 0 || nbRow2 < 0 || nbCol1 < 0 || nbCol2 < 0 || modulus < 1){
        throw std::runtime_error("Les nombres de lignes et de colonnes dovent etre "
											"des entiers positifs ou nuls. Le modulo "
                                 "doit etre un entier plus grand que 0.");
    }
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
    /*srand (time(NULL));
    std::cout << matrix << std::endl;
    Matrix matrix1(3,2,8);
    std::cout << matrix1 << std::endl;
    matrix.addItself(matrix1);
    std::cout << matrix << std::endl;
    matrix.subItself(matrix1);
    std::cout << matrix << std::endl;

*/
    return 0;
}
