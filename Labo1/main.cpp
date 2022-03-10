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
        throw std::runtime_error("Le nombre de ligne, de colonne doit etre un entier positif et le modulo "
                                 "doit etre un entier plus grand que 0.");
    }
    srand (time(NULL));
    Matrix matrix1(nbRow1,nbCol1,modulus);
    Matrix matrix2(nbRow2,nbCol2,modulus);
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
    std::cout << matrix << std::endl;*/


    return 0;
}
