#ifndef INTERNAL_MATRIX_H
#define INTERNAL_MATRIX_H

//#include "Matrix.h"
#include <string>

class InternalMatrix {
public:
    InternalMatrix();
    InternalMatrix(char a, char b, char c, char d);
    ~InternalMatrix();

    void xorWithOtherMatrix(const InternalMatrix& other);
    std::string getMatrixByString() const;
    void setMatrix(char a, char b, char c, char d);
    void rotateRight();
    void rotateLeft();
private:
    char matrix[2][2] = { 0 };
;
};

#endif // INTERNAL_MATRIX_H
