#include <iostream>
#include "Cube.h"
#include "Matrix.h"

int main() {
    Matrix<int> mat(3, 3);
    mat.setValue(0, 0, 1);
    mat.setValue(0, 1, 2);
    mat.setValue(1, 0, 3);

    int value = mat.getValue(1, 0); // Get the value at position (1, 0)
    std::cout << "Value at position (1, 0): " << value << std::endl;

    //Cube cube(1); // Creating a cube with size 3
    //std::string bits = "000000010000001000000011"; // Example string of bits

    //cube.stringInsertion(bits); // Inserting bits into the cube
    //cube.rightRotation(0); // Rotating the cube to the right

    //std::string extractedBits = cube.stringExtraction(); // Extracting bits from the cube
    //std::cout << "Extracted bits: " << extractedBits << std::endl;

    return 0;
}
