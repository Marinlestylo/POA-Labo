#include <iostream>
#include "matrix.h"

int main() {
    srand (time(NULL));
    Matrix matrix(2,2,4);
    std::cout << matrix << std::endl;
    return 0;
}
