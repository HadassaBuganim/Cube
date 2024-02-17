#ifndef INTERNALMATRIX_H
#define INTERNALMATRIX_H

#include "Matrix.h"
#include <string>

class InternalMatrix {
public:
    InternalMatrix();
    InternalMatrix(char a, char b, char c, char d);
    ~InternalMatrix();
    void XORWithMatrix(const InternalMatrix& other);
    std::string matrixToString() const;
    void changeMatrix(char a, char b, char c, char d);
private:
    Matrix<char>* matrix;
};

#endif // INTERNALMATRIX_H
