#include <iostream>
#include "matrix.h"

int main() {
    srand (time(NULL));
    Matrix matrix(2,2,8);
    std::cout << matrix << std::endl;
    Matrix matrix1 = matrix;
    std::cout << matrix1 << std::endl;

    return 0;
}
