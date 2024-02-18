//#include "Cube.h"
//#include <iostream>
//#include <vector>
//Cube::Cube(int size) : cubeSize(size) {
//    wigs = new CubeWig[6];
//    for (int i = 0; i < 6; ++i) {
//        wigs[i] = CubeWig(size);
//    }
//}
//
//Cube::~Cube() {
//    delete[] wigs;
//}
//
//void Cube::rightRotation(int index) {
//    wigs[index].rotateWigLeft();
//}
//
//void Cube::leftRotation(int index) {
//    // Rotate matrix at position index in the array of wigs to the left
//}
//
//void Cube::stringInsertion(const std::string& bits) {
//    std::vector<std::string> dividedStrings;
//    int partLength = bits.length() / 6;
//    for (int i = 0; i < 6; ++i) {
//        int startIndex = i * partLength;
//        std::string part = bits.substr(startIndex, partLength);
//        dividedStrings.push_back(part);
//    }
//    for (int i = 0; i < 6; i++)
//    {
//        wigs[i].stringInsertion(dividedStrings[i]);
//    }
//}
//
//std::string Cube::stringExtraction() const {
//    std::string str = "";
//    for (int i = 0; i < 6; i++)
//    {
//        str += wigs[i].stringExtraction();
//    }
//    return str;
//}
