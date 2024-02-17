#include "Cube.h"
#include <iostream>

Cube::Cube(int size) : cubeSize(size) {
    wigs = new CubeWig[6];
    for (int i = 0; i < 6; ++i) {
        wigs[i] = CubeWig(size);
    }
}

Cube::~Cube() {
    delete[] wigs;
}

void Cube::rightRotation(int index) {
    // Rotate matrix at position index in the array of wigs to the right
}

void Cube::leftRotation(int index) {
    // Rotate matrix at position index in the array of wigs to the left
}

void Cube::stringInsertion(const std::string& bits) {
    // Divide the string into 6 equal parts and insert into each wig
}

std::string Cube::stringExtraction() const {
    // Extract bits from internal matrices of dice's edges
    return "";
}
#include "Cube.h"
#include <iostream>

Cube::Cube(int size) : cubeSize(size) {
    wigs = new CubeWig[6];
    for (int i = 0; i < 6; ++i) {
        wigs[i] = CubeWig(size);
    }
}

Cube::~Cube() {
    delete[] wigs;
}

void Cube::rightRotation(int index) {
    // Rotate matrix at position index in the array of wigs to the right
}

void Cube::leftRotation(int index) {
    // Rotate matrix at position index in the array of wigs to the left
}

void Cube::stringInsertion(const std::string& bits) {
    // Divide the string into 6 equal parts and insert into each wig
}

std::string Cube::stringExtraction() const {
    // Extract bits from internal matrices of dice's edges
    return "";
}
