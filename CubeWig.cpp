#include "CubeWig.h"

CubeWig::CubeWig(int size)
{
    wigSize = size;
    /*matrix = new InternalMatrix * [size];
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new InternalMatrix[size];
    }*/
    matrix = new InternalMatrix*[1];
    matrix[0] = new InternalMatrix[1];

}
CubeWig::CubeWig()
{
    wigSize = 3;
    matrix = new InternalMatrix * [3];
    for (size_t i = 0; i < 3; i++)
    {
        matrix[i] = new InternalMatrix[3];
    }
}

CubeWig::~CubeWig() 
{
    for (size_t i = 0; i < wigSize; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void CubeWig::changeMatrix(int i, int j, char a, char b, char c, char d) {
    matrix[i][j].setMatrix(a, b, c, d);
}

std::string CubeWig::getInternalMatrixByString(int i, int j) const {
    return matrix[i][j].getMatrixByString();
}
InternalMatrix CubeWig::getInternalMatrix(int i, int j)
{
    return matrix[i][j];
}

void CubeWig::insertString(const std::string& bits)
{
    int stringIndex = 0;
    for (int i = 0; i < wigSize; i++)
    {
        for (int j = 0; j < wigSize; j++)
        {
            if (stringIndex < bits.size())
            {
                char a = bits[stringIndex++];
                char b = bits[stringIndex++];
                char c = bits[stringIndex++];
                char d = bits[stringIndex++];
                changeMatrix(i, j, a, b, c, d);
            }
        }
    }
}

std::string CubeWig::extractString() const {
    std::string str = "";
    for (int i = 0; i < wigSize; i++)
    {
        for (int j = 0; j < wigSize; j++)
        {
            str += matrix[i][j].getMatrixByString();
        }
    }
    return str;
}
void CubeWig::rotateLeft()
{
    for (int i = 0; i < wigSize; i++)
    {
        for (int j = 0; j < wigSize; j++)
        {
            matrix[i][j].rotateLeft();
        }
    }
   InternalMatrix** temp = new InternalMatrix * [wigSize];
   for (size_t i = 0; i < wigSize; i++)
   {
       temp[i] = new InternalMatrix[wigSize];
       for (size_t j = 0; j < wigSize; j++)
       {
           temp[i][j] = matrix[j][wigSize - 1 - i];
       }
   }
   for (size_t i = 0; i < wigSize; i++)
   {
       delete[] matrix[i];
   }
   delete[] matrix;
   matrix = temp;
}
CubeWig CubeWig::operator=(CubeWig wig)
{
    for (size_t i = 0; i < wig.wigSize; i++)
    {
        for (size_t j = 0; j < wig.wigSize; j++)
        {
            this->matrix[i][j] = wig.matrix[i][j];
        }
    }
    this->wigSize = wig.wigSize;
    return *this;
}
void CubeWig::rotateRight()
{
    for (int i = 0; i < wigSize; i++)
    {
        for (int j = 0; j < wigSize; j++)
        {
            matrix[i][j].rotateRight();
        }
    }
    InternalMatrix** temp = new InternalMatrix * [wigSize];
   for (size_t i = 0; i < wigSize; i++)
   {
       temp[i] = new InternalMatrix[wigSize];
       for (size_t j = 0; j < wigSize; j++)
       {
           temp[i][j] = matrix[wigSize - 1 - j][i];
       }
   }
   for (size_t i = 0; i < wigSize; i++)
   {
       delete[] matrix[i];
   }
   delete[] matrix;
   matrix = temp;

}

