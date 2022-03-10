#include <iostream>
#include "matrix.h"

int main() {
    srand (time(NULL));
    Matrix matrix(2,2,8);
    std::cout << matrix << std::endl;
    Matrix matrix1(3,2,8);
    std::cout << matrix1 << std::endl;
    matrix.addItself(matrix1);
    std::cout << matrix << std::endl;
    Matrix c(matrix);
    Matrix d = matrix.addStaticNew(matrix1);
    Matrix* e = matrix.addDynamicNew(matrix1);
    std::cout << c << std::endl << d << std::endl << *e<< std::endl;
    std::cout << matrix << std::endl;

    return 0;
}
