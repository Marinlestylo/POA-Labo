#include <iostream>
#include "matrix.h"
int main() {
    Matrix matrix(2,2,4);
    std::cout << matrix.getVal(0,0) << std::endl;
    return 0;
}
