//
// Created by Jonathan on 24.02.2022.
//

#include "matrix.h"
#include "add.h"
#include "operation.h"
#include "substract.h"
#include "multiply.h"

Matrix::Matrix(size_t row,size_t col,unsigned mod) : row(row), col(col), mod(mod){
    generateMatrix();
}

Matrix::Matrix(const Matrix &matrix){
    row = matrix.getRow();
    col = matrix.getCol();
    values = new unsigned*[row];
    for (size_t i = 0; i < row; ++i) {
        values[i] = new unsigned[col];
    }
    *this = matrix;
}

Matrix::~Matrix() {
    delete [] values;
}

Matrix &Matrix::operator=(const Matrix &other) {
    this->row = other.getRow();
    this->col = other.getCol();
    this->mod = other.getMod();
    unsigned ** newValues = new unsigned*[row];
    for (size_t i = 0; i < row; ++i) {
        newValues[i] = new unsigned[col];
    }
    std::swap(values,newValues);
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            values[i][j] = other.getVal(i,j);
        }
    }
    delete[] newValues;
    return *this;
}



unsigned Matrix::getVal(size_t row,size_t col) const{
    return values[row][col];
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix){
    for (size_t i = 0; i < matrix.getRow(); ++i) {
        for (size_t j = 0; j < matrix.getCol(); ++j) {
            os << matrix.getVal(i,j) << " ";
        }
        os << std::endl;
    }
    return os;
}

void Matrix::generateMatrix() {
    values = new unsigned*[row];
    for (size_t i = 0; i < row; ++i) {
        values[i] = new unsigned[col];
        for (size_t j = 0; j < col; ++j) {
            values[i][j] = randomNumber();
        }
    }
}

void Matrix::addItself(const Matrix &matrix){
    applyOperator(matrix,new Add());
}

Matrix Matrix::addStaticNew(const Matrix &matrix) {
    Matrix m(*this);
    m.addItself(matrix);
    return m;
}

Matrix *Matrix::addDynamicNew(const Matrix &matrix) {
    Matrix* m = new Matrix(*this);
    m->addItself(matrix);
    return m;
}

void Matrix::subItself(const Matrix &matrix) {
    applyOperator(matrix,new Substract());
}
void Matrix::multItself(const Matrix &matrix) {
    applyOperator(matrix,new Multiply());
}

Matrix* Matrix::applyOperator(const Matrix &matrix,Operation* op){
    if(this->getMod() != matrix.getMod()){
        //TODO Throw exception
        return nullptr;
    }

    size_t newRow = std::max(this->getRow(),matrix.getRow());
    size_t newCol = std::max(this->getCol(),matrix.getCol());
    unsigned** newMatrix = new unsigned*[newRow];
    for (size_t i = 0; i < newRow; ++i) {
        newMatrix[i] = new unsigned[newCol];
    }

    for (int i = 0; i < newRow; ++i) {
        for (int j = 0; j < newCol; ++j) {
            unsigned a = i >= this->getRow() || j >= this->col ? 0:this->getVal(i,j);
            unsigned b = i >= matrix.getRow() || j >= matrix.getCol() ? 0:matrix
                    .getVal(i,j);
            newMatrix[i][j] = op->apply(a,b) % mod;
        }
    }
    std::swap(values,newMatrix);
    this->row = newRow;
    this->col = newCol;

    //TODO Delete correctement la matrice newMatrix
    delete[] newMatrix;
    return this;
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