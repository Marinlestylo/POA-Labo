//
// Created by Jonathan on 24.02.2022.
//

#include "matrix.h"

Matrix::Matrix(size_t n,size_t m,unsigned mod) : n(n),m(m),mod(mod){
    generateMatrix();
}

Matrix::~Matrix() {

}

void Matrix::generateMatrix() {
    values = new unsigned*[n];
    for (int i = 0; i < n; ++i) {
        values[i] = new unsigned[m];
        for (int j = 0; j < m; ++j) {
            values[i][j] = randomNumber();
        }
    }
}

unsigned Matrix::randomNumber(){
    return rand() % mod;
}

unsigned int Matrix::getMod() const {
    return mod;
}

size_t Matrix::getN() const {
    return n;
}

size_t Matrix::getM() const {
    return m;
}

void Matrix::printMatrix(){

}