#include "InternalMatrix.h"
#include <iostream>

InternalMatrix::InternalMatrix() {
    matrix = new Matrix<char>(2, 2);
    matrix->setValue(0, 0, 0);
    matrix->setValue(0, 1, 0);
    matrix->setValue(1, 0, 0);
    matrix->setValue(1, 1, 0);
}

InternalMatrix::InternalMatrix(char a, char b, char c, char d) {
    matrix = new Matrix<char>(2, 2);
    matrix->setValue(0, 0, a);
    matrix->setValue(0, 1, b);
    matrix->setValue(1, 0, c);
    matrix->setValue(1, 1, d);
    //changeMatrix(a, b, c, d);
}

InternalMatrix::~InternalMatrix() {
    matrix->~Matrix();
}

void InternalMatrix::XORWithMatrix(const InternalMatrix& otherMatrix) {
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            char b = matrix->getValue(i,j) ^ (otherMatrix.matrix)->getValue(i,j);
            matrix->setValue(i, j, b);
        }
    }
}

std::string InternalMatrix::matrixToString() const {
    // Convert matrix to string
    return "";
}

void InternalMatrix::changeMatrix(char a, char b, char c, char d) {
    // Change matrix according to received bits
}
