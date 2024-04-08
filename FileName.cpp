#include <iostream>
#include "Cube.h"
#include "Matrix.h"

int main() {
    //Cube cube(3); // Creating a cube of size 3

    //std::string bits = "010101010101010101010101"; // Sample bits
    //cube.insertString(bits); // Inserting bits into the cube

    //cube.rotateRight(0); // Rotating the first wig to the right

    //std::string extractedBits = cube.extractString(); // Extracting bits from the cube
    //std::cout << "Extracted bits: " << extractedBits << std::endl;
    //Matrix mat(2, 2);
    ////mat.~Matrix();
    //mat.rotateLeft();
    //return 0;
    std::string input = "000110010000001000010011000000010011001000000111";
    Cube c(4);
    c.insertString(input);
    c.rotate(1, LEFT);
    std::string output = c.extructString();
    std::cout << output << std::endl;

}
