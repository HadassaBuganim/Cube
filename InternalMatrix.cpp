#include "InternalMatrix.h"

InternalMatrix::InternalMatrix(){
    matrix[0][0] = matrix[0][1] = matrix[1][0] = matrix[1][1] = 0;
}

InternalMatrix::InternalMatrix(char a, char b, char c, char d){
    setMatrix(a, b, c, d);
}

InternalMatrix::~InternalMatrix() {}

void InternalMatrix::xorWithOtherMatrix(const InternalMatrix& otherMatrix)
{
    for (size_t i = 0; i < 2; i++)
    {
        for (size_t j = 0; j < 2; j++)
        {
            matrix[i][j] ^= otherMatrix.matrix[i][j];
        }
    }
}

std::string InternalMatrix::getMatrixByString() const 
{
    char chars[] = { matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1] };
    std::string str;
    for (int i = 0; i < 4; ++i) {
        str += chars[i];
    }
    return str;
}
void InternalMatrix::setMatrix(char a, char b, char c, char d)
{
    matrix[0][0] = a;
    matrix[0][1] = b;
    matrix[1][0] = c;
    matrix[1][1] = d;
}
void InternalMatrix::rotateRight()
{
    char temp = matrix[0][0];
    matrix[0][0] = matrix[1][0];
    matrix[1][0] = matrix[1][1];
    matrix[1][1] = matrix[0][1];
    matrix[0][1] = temp;
}
void InternalMatrix::rotateLeft()
{
    char temp = matrix[0][0];
    matrix[0][0] = matrix[0][1];
    matrix[0][1] = matrix[1][1];
    matrix[1][1] = matrix[1][0];
    matrix[1][0] = temp;
}
