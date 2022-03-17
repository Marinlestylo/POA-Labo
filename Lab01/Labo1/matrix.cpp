/*
-----------------------------------------------------------------------------------
Nom du fichier  : matrix.cpp
Auteur(s)       : Alexandre Jaquier, Jonathan Friedli
Date creation   : 03.03.2022
Description     : Fichier contenant l'implémentation de la classe Matrix.
Compilateur     : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/

#include "matrix.hpp"
#include "add.hpp"
#include "substract.hpp"
#include "multiply.hpp"
#include "utils.hpp"

Matrix::Matrix(size_t row, size_t col, unsigned mod) : row(row), col(col), mod(mod){
    if(mod == 0){
        throw std::runtime_error("Modulo invalide");
    }
    generateMatrix();
}

Matrix::Matrix(const Matrix &other){
    row = other.row;
    col = other.col;
    mod = other.mod;
    values = new unsigned*[row];
    for (size_t i = 0; i < row; ++i) {
        values[i] = new unsigned[col];
    }
    replaceValues(other);
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

void Matrix::replaceValues(const Matrix &other){
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            values[i][j] = other.getVal(i,j);
        }
    }
}

Matrix &Matrix::operator=(const Matrix &other) {
    if(this != &other){

        changeSizeValues(other.row,other.col);
        this->row = other.row;
        this->col = other.col;
        this->mod = other.mod;
        replaceValues(other);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix){
    for (size_t i = 0; i < matrix.row; ++i) {
        for (size_t j = 0; j < matrix.col; ++j) {
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
            values[i][j] = Utils::randomNumber(mod);
        }
    }
}

Matrix& Matrix::addItself(const Matrix &matrix){
    static Add* add = new Add();
    applyOperator(matrix,add);
    return *this;
}

Matrix Matrix::addStaticNew(const Matrix &matrix) const{
    Matrix m(*this);
	 m.addItself(matrix);
    return m;
}

Matrix *Matrix::addDynamicNew(const Matrix &matrix) const{
    Matrix* m = new Matrix(*this);
    try{
        m->addItself(matrix);
    } catch(const std::invalid_argument& e){
        delete m;
        throw;
    }
    return m;
}

Matrix& Matrix::subItself(const Matrix &matrix) {
    static Substract* sub = new Substract();
    applyOperator(matrix,sub);
    return *this;
}
Matrix Matrix::subStaticNew(const Matrix &matrix) const{
    Matrix m(*this);
	 m.subItself(matrix);
    return m;
}

Matrix *Matrix::subDynamicNew(const Matrix &matrix) const{
    Matrix* m = new Matrix(*this);
    try{
        m->subItself(matrix);
    } catch(const std::invalid_argument& e){
        delete m;
        throw;
    }
    return m;
}
Matrix& Matrix::multItself(const Matrix &matrix){
    static Multiply* mult = new Multiply();
    applyOperator(matrix,mult);
    return *this;
}
Matrix Matrix::multStaticNew(const Matrix &matrix) const{
    Matrix m(*this);
	 m.multItself(matrix);
    return m;
}

Matrix *Matrix::multDynamicNew(const Matrix &matrix) const{
    Matrix* m = new Matrix(*this);
    try{
        m->multItself(matrix);
    } catch(const std::invalid_argument& e){
        delete m;
        throw;
    }
    return m;
}

void Matrix::changeSizeValues(size_t row, size_t col){
    if(this->row == row && this->col == col) {
        return;
    }
        unsigned** newValues = new unsigned*[row];
    for (size_t i = 0; i < row; ++i) {
        newValues[i] = new unsigned[col];
    }
    for (size_t i = 0; i < row; ++i) {
        for (size_t j = 0; j < col; ++j) {
            newValues[i][j] = this->getVal(i,j);
        }
    }
    deleteValues();
    this->row = row;
    this->col = col;
    values = newValues;
}

Matrix* Matrix::applyOperator(const Matrix &matrix, Operation* op){
    if(this->mod != matrix.mod){
        throw std::invalid_argument("Les modulos des deux matrices ne sont pas "
                                    "egaux");
    }
    changeSizeValues(std::max(this->row, matrix.row),std::max(this->col,matrix.col));

    for (size_t i = 0; i < this->row; ++i) {
        for (size_t j = 0; j < this->col; ++j) {
            values[i][j] = Utils::floorMod(op->apply(this->getVal(i,j), matrix
            .getVal(i,j)),mod);
        }
    }
    return this;
}

unsigned Matrix::getVal(size_t row, size_t col) const{
    if(row >= this->row || col >= this->col){
        return 0;
    }
    return values[row][col];
}