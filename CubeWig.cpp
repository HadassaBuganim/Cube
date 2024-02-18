//#include "CubeWig.h"
//#include <iostream>
//
//CubeWig::CubeWig(int size) : wigSize(size) {
//    wig = new Matrix<InternalMatrix>*[wigSize];
//    for (int i = 0; i < wigSize; ++i) {
//        wig[i] = new Matrix<InternalMatrix>(size, size);
//    }
//}
//CubeWig::CubeWig() : wigSize(3) {
//    wig = new Matrix<InternalMatrix> * [wigSize];
//    for (int i = 0; i < wigSize; ++i) {
//        wig[i] = new Matrix<InternalMatrix>(3,3);
//    }
//}
//
//CubeWig::~CubeWig() {
//    for (int i = 0; i < wigSize; ++i) {
//        delete[] wig[i];
//    }
//    delete[] wig;
//}
////InternalMatrix CubeWig::getSmallMatrix(int i, int j)
////{
////  
////}
//
//void CubeWig::smallMatrixChange(int i, int j, char a, char b, char c, char d) {
//    wig[i][j].getValue(i, j).changeMatrix(a, b, c, d);
//}
//
//std::string CubeWig::internalMatrixReturn(int i, int j) const {
//    return wig[i][j].getValue(i,j).matrixToString();
//}
//
//void CubeWig::stringInsertion(const std::string& str) {
//    int stringIndex = 0;
//    for (int i = 0; i < wigSize; i++)
//    {
//        for (int j = 0; j < wigSize; j++)
//        {
//            //להוסיף תנאי-יתכן מצב שבו המחרוזת לא מתחלקת ב4 ואז זה יפול
//            if (stringIndex < str.size())
//            {
//                char a = str[stringIndex++];
//                char b = str[stringIndex++];
//                char c = str[stringIndex++];
//                char d = str[stringIndex++];
//                smallMatrixChange(i, j, a, b, c, d);
//            }
//        }
//    }
//}
//
//std::string CubeWig::stringExtraction(){
//    std::string str = "";
//    for (size_t i = 0; i < wigSize; i++)
//    {
//        for (size_t j = 0; j < wigSize; j++)
//        {
//            str += internalMatrixReturn(i, j);
//        }
//    }
//    return str;
//}
//void CubeWig::rotateWigLeft() {
//    for (size_t i = 0; i < wigSize; i++)
//    {
//        for (size_t j = 0; j < wigSize; j++)
//        {
//            wig[i][j].rotateLeft();
//        }
//    }
//    Matrix<InternalMatrix>** temp = new Matrix<InternalMatrix>* [wigSize];
//    for (int i = 0; i < wigSize; i++)
//    {
//        temp[i] = new Matrix<InternalMatrix>(wigSize, wigSize);
//        for (int j = 0; j < wigSize; j++)
//            {
//                temp[i][j] = wig[j][wigSize - 1 - i];
//            }
//    }
//    for (size_t i = 0; i < wigSize; i++)
//    {
//        delete[] wig[i];
//    }
//    delete[] wig;
//    wig = temp;
//}
