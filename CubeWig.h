#ifndef CUBE_WIG_H
#define CUBE_WIG_H

//#include "Matrix.h"
#include "InternalMatrix.h"
#include <vector>

class CubeWig{
public:
    CubeWig(int size);
    CubeWig();
    ~CubeWig();

    void changeMatrix(int i, int j, char a, char b, char c, char d);
    std::string getInternalMatrixByString(int i, int j) const;
    InternalMatrix getInternalMatrix(int i, int j);
    void insertString(const std::string& bits);
    std::string extractString() const;
    void rotateRight();
    void rotateLeft();
    //CubeWig operator=(CubeWig& wig);
private:
    std::vector<std::vector<InternalMatrix> > matrix = {};
    ///InternalMatrix** matrix = nullptr;
    int wigSize;
};

#endif // CUBE_WIG_H
