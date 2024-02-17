#include "CubeWig.h"
#include <iostream>

CubeWig::CubeWig(int size) : wigSize(size) {
    matrices = new InternalMatrix * [wigSize];
    for (int i = 0; i < wigSize; ++i) {
        matrices[i] = new InternalMatrix[size];
    }
}

CubeWig::~CubeWig() {
    for (int i = 0; i < wigSize; ++i) {
        delete[] matrices[i];
    }
    delete[] matrices;
}

void CubeWig::smallMatrixChange(int i, int j, bool a, bool b, bool c, bool d) {
    // Change internal matrix at position i,j
}

std::string CubeWig::internalMatrixReturn(int i, int j) const {
    // Return string of bits representing internal matrix at position i,j
    return "";
}

void CubeWig::stringInsertion(const std::string& bits) {
    // Insert bits into each internal matrix
}

std::string CubeWig::stringExtraction() const {
    // Extract bits from all internal matrices
    return "";
}
#include "CubeWig.h"
#include <iostream>

CubeWig::CubeWig(int size) : wigSize(size) {
    matrices = new InternalMatrix * [wigSize];
    for (int i = 0; i < wigSize; ++i) {
        matrices[i] = new InternalMatrix[size];
    }
}

CubeWig::~CubeWig() {
    for (int i = 0; i < wigSize; ++i) {
        delete[] matrices[i];
    }
    delete[] matrices;
}

void CubeWig::smallMatrixChange(int i, int j, bool a, bool b, bool c, bool d) {
    // Change internal matrix at position i,j
}

std::string CubeWig::internalMatrixReturn(int i, int j) const {
    // Return string of bits representing internal matrix at position i,j
    return "";
}

void CubeWig::stringInsertion(const std::string& bits) {
    // Insert bits into each internal matrix
}

std::string CubeWig::stringExtraction() const {
    // Extract bits from all internal matrices
    return "";
}
