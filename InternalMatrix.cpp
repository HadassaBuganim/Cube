//#include "InternalMatrix.h"
//#include <iostream>
//
//InternalMatrix::InternalMatrix() {
//    matrixChar = new Matrix<char>(2, 2);
//    matrixChar->setValue(0, 0, 0);
//    matrixChar->setValue(0, 1, 0);
//    matrixChar->setValue(1, 0, 0);
//    matrixChar->setValue(1, 1, 0);
//}
//
//InternalMatrix::InternalMatrix(char a, char b, char c, char d) {
//    matrixChar = new Matrix<char>(2, 2);
//    matrixChar->setValue(0, 0, a);
//    matrixChar->setValue(0, 1, b);
//    matrixChar->setValue(1, 0, c);
//    matrixChar->setValue(1, 1, d);
//    //changeMatrix(a, b, c, d);
//}
//
//InternalMatrix::~InternalMatrix() {
//    matrixChar->~Matrix();
//}
//
//void InternalMatrix::XORWithMatrix(const InternalMatrix& otherMatrix) {
//    for (int i = 0; i < 2; i++)
//    {
//        for (int j = 0; j < 2; j++)
//        {
//            char b = matrixChar->getValue(i,j) ^ (otherMatrix.matrixChar)->getValue(i,j);
//            matrixChar->setValue(i, j, b);
//        }
//    }
//}
//
//std::string InternalMatrix::matrixToString() const {
//    char chars[] = { matrixChar->getValue(0,0), matrixChar->getValue(0,1), matrixChar->getValue(1,0), matrixChar->getValue(1,1) };
//    std::string str;
//    for (int i = 0; i < 4; ++i) {
//        str += chars[i];
//    }
//    return str;
//}
//
//void InternalMatrix::changeMatrix(char a, char b, char c, char d) {
//    matrixChar->setValue(0, 0, a);
//    matrixChar->setValue(0, 1, b);
//    matrixChar->setValue(1, 0, c);
//    matrixChar->setValue(1, 1, d);
//}
