//
// Created by Jonathan on 24.02.2022.
//

#ifndef LABO1_MATRIX_H
#define LABO1_MATRIX_H

#include <iostream>
#include <cstdlib>
#include <ctime>



class Matrix {
public:
    Matrix(size_t n,size_t m,unsigned mod);
    ~Matrix();
    unsigned int getMod() const;

    size_t getN() const;

    size_t getM() const;
    void printMatrix();
    unsigned getVal(int i,int j){
        return values[i][j];
    }

private:
    void generateMatrix();
    unsigned randomNumber();

    unsigned mod;
    size_t n,m;
    unsigned** values;
};
#endif //LABO1_MATRIX_H
