#include <iostream>
#include "Cube.h"

int main() {
    Cube cube(3); // Creating a cube with size 3
    std::string bits = "1100110011001100"; // Example string of bits

    cube.stringInsertion(bits); // Inserting bits into the cube
    cube.rightRotation(0); // Rotating the cube to the right

    std::string extractedBits = cube.stringExtraction(); // Extracting bits from the cube
    std::cout << "Extracted bits: " << extractedBits << std::endl;

    return 0;
}
#include <iostream>
#include "Cube.h"

int main() {
    Cube cube(3); // Creating a cube with size 3
    std::string bits = "1100110011001100"; // Example string of bits

    cube.stringInsertion(bits); // Inserting bits into the cube
    cube.rightRotation(0); // Rotating the cube to the right

    std::string extractedBits = cube.stringExtraction(); // Extracting bits from the cube
    std::cout << "Extracted bits: " << extractedBits << std::endl;

    return 0;
}
