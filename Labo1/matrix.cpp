//
// Created by Jonathan on 24.02.2022.
//

#include "matrix.h"

Matrix::Matrix(size_t row,size_t col,unsigned mod) : row(row), col(col), mod(mod){
    generateMatrix();
}

Matrix::Matrix(const Matrix &matrix){
    
}

Matrix::~Matrix() {

}

Matrix &Matrix::operator=(const Matrix &other) {
    return *this;
}

unsigned Matrix::getVal(size_t row,size_t col) const{
    return values[row][col];
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix){
    for (unsigned i = 0; i < matrix.getRow(); ++i) {
        for (unsigned j = 0; j < matrix.getCol(); ++j) {
            os << matrix.getVal(i,j) << " ";
        }
        os << std::endl;
    }
    return os;
}

void Matrix::generateMatrix() {
    values = new unsigned*[row];
    for (unsigned i = 0; i < row; ++i) {
        values[i] = new unsigned[col];
        for (unsigned j = 0; j < col; ++j) {
            values[i][j] = randomNumber();
        }
    }
}

unsigned Matrix::randomNumber(){
    return (unsigned)rand() % mod;
}

unsigned int Matrix::getMod() const {
    return mod;
}

size_t Matrix::getRow() const {
    return row;
}

size_t Matrix::getCol() const {
    return col;
}

void Matrix::printMatrix(){

}