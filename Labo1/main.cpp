#include <iostream>
#include "matrix.h"

int main(int argc, char *argv[]) {
    /*if(argc != 5){
        throw std::runtime_error("Pas le bon nombre d'argument.");
    }*/
    srand (time(NULL));
    Matrix matrix(2,2,8);
    matrix.getVal(100, 100);
    /*
    std::cout << matrix << std::endl;
    Matrix matrix1(3,2,8);
    std::cout << matrix1 << std::endl;
    matrix.addItself(matrix1);
    std::cout << matrix << std::endl;
    matrix.subItself(matrix1);
    std::cout << matrix << std::endl;*/


    return 0;
}
