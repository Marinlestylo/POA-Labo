/*
-----------------------------------------------------------------------------------
Nom du fichier  : matrix.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 10.03.2022
Description     : Fichier contenant l'implémentation de la classe Matrix.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "matrix.h"
#include "add.h"
#include "substract.h"
#include "multiply.h"

Matrix::Matrix(size_t row, size_t col, unsigned mod) : row(row), col(col), mod(mod){
    if(mod == 0){
        throw std::runtime_error("Modulo invalide");
    }
    generateMatrix();
}

Matrix::Matrix(const Matrix &matrix){
    row = matrix.getRow();
    col = matrix.getCol();
    mod = matrix.getMod();
    values = new unsigned*[row];
    for (size_t i = 0; i < row; ++i) {
        values[i] = new unsigned[col];
    }
    *this = matrix;
}

Matrix::~Matrix() {
    deleteValues();
}

void Matrix::deleteValues() {
    for (size_t i = 0; i < row; ++i) {
        delete[] values[i];
    }
    delete[] values;
}

Matrix &Matrix::operator=(const Matrix &other) {
    if(this != &other){
        this->row = other.getRow();
        this->col = other.getCol();
        this->mod = other.getMod();
        if(this->row != other.getRow() || this->col != other.getCol()){
            changeSizeValues(this->row,this->col);
        }
        for (size_t i = 0; i < row; ++i) {
            for (size_t j = 0; j < col; ++j) {
                values[i][j] = other.getVal(i,j);
            }
        }
    }
    return *this;
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

Matrix& Matrix::addItself(const Matrix &matrix){
    static Add* op = new Add();
    applyOperator(matrix,op);
    return *this;
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

Matrix& Matrix::subItself(const Matrix &matrix) {
    static Substract* op = new Substract();
    applyOperator(matrix,op);
    return *this;
}
Matrix Matrix::subStaticNew(const Matrix &matrix) {
    Matrix m(*this);
    m.subItself(matrix);
    return m;
}

Matrix *Matrix::subDynamicNew(const Matrix &matrix) {
    Matrix* m = new Matrix(*this);
    m->subItself(matrix);
    return m;
}
Matrix& Matrix::multItself(const Matrix &matrix) {
    static Multiply* op = new Multiply();
    applyOperator(matrix,op);
    return *this;
}
Matrix Matrix::multStaticNew(const Matrix &matrix) {
    Matrix m(*this);
    m.multItself(matrix);
    return m;
}

Matrix *Matrix::multDynamicNew(const Matrix &matrix) {
    Matrix* m = new Matrix(*this);
    m->multItself(matrix);
    return m;
}

void Matrix::changeSizeValues(size_t row, size_t col){
    unsigned** newValues = new unsigned*[row];
    for (size_t i = 0; i < row; ++i) {
        newValues[i] = new unsigned[col];
    }
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            newValues[i][j] = i >= this->row || j >= this->col ? 0 : values[i][j];
        }
    }
    deleteValues();
    this->row = row;
    this->col = col;
    values = newValues;
}

Matrix* Matrix::applyOperator(const Matrix &matrix, Operation* op){
    if(this->mod != matrix.getMod()){
        throw std::invalid_argument("Les modulos ne sont pas egaux");
    }
    if(this->row < matrix.row || this->col < matrix.col)
        changeSizeValues(std::max(this->row, matrix.row),std::max(this->col,matrix
        .col));

    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < this->col; ++j) {
            unsigned a = this->getVal(i,j);
            unsigned b = i >= matrix.getRow() || j >= matrix.getCol() ? 0:matrix
                    .getVal(i,j);
            values[i][j] = op->apply(a+mod,b) % mod;
        }
    }
    return this;
}

unsigned Matrix::randomNumber(){
    return (unsigned)rand() % mod;
}

unsigned Matrix::getVal(size_t row, size_t col) const{
    if(row >= this->row || col >= this->col){
        throw std::runtime_error("Vous tentez d'acceder a des index invalides de la matrice");
    }
    return values[row][col];
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