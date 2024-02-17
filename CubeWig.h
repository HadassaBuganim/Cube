#ifndef CUBEWIG_H
#define CUBEWIG_H

#include "InternalMatrix.h"

class CubeWig {
public:
    CubeWig(int size);
    ~CubeWig();
    void smallMatrixChange(int i, int j, bool a, bool b, bool c, bool d);
    std::string internalMatrixReturn(int i, int j) const;
    void stringInsertion(const std::string& bits);
    std::string stringExtraction() const;
private:
    int wigSize;
    InternalMatrix** matrices;
};

#endif // CUBEWIG_H
