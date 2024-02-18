#include "Matrix.h"
#include <iostream>

template<typename T>
Matrix<T>::Matrix(int row, int column) : rowSize(row), columnSize(column) {
    matrix = new T * [rowSize];
    for (int i = 0; i < rowSize; ++i) {
        matrix[i] = new T[columnSize];
    }
}

template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rowSize; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template<typename T>
void Matrix<T>::rotateRight() {
	if (rowSize == columnSize)
	{
		T** temp = new T * [rowSize];
		for (size_t i = 0; i < rowSize; i++)
		{
			temp[i] = new T[columnSize];
			for (size_t j = 0; j < columnSize; j++)
			{
				temp[i][j] = matrix[columnSize - 1 - j][i];
			}
		}
		for (size_t i = 0; i < rowSize; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = temp;
	}
}

template<typename T>
void Matrix<T>::rotateLeft() {
	if (rowSize == columnSize)
	{
		T** temp = new T * [rowSize];
		for (size_t i = 0; i < rowSize; i++)
		{
			temp[i] = new T[columnSize];
			for (size_t j = 0; j < columnSize; j++)
			{
				temp[i][j] = matrix[j][columnSize - 1 - i];
			}
		}
		for (size_t i = 0; i < rowSize; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;
		matrix = temp;
	}
}
template<typename T>
T* Matrix<T>::operator[](int index) {
	return matrix[index];
}
template<typename T>
void Matrix<T>::setValue(int row, int column, const T& value) {
	if (row >= 0 && row < rowSize && column >= 0 && column < columnSize) {
		matrix[row][column] = value;
	}
	else {
		// Handle out-of-range error
		std::cerr << "Error: Indices out of range." << std::endl;
	}
}
template<typename T>
T Matrix<T>::getValue(int row, int column) const {
	if (row >= 0 && row < rowSize && column >= 0 && column < columnSize) {
		return matrix[row][column];
	}
	else {
		// Handle out-of-range error
		std::cerr << "Error: Indices out of range." << std::endl;
		return T(); // Return a default value of type T
	}
}
