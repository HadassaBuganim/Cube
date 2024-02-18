#ifndef MATRIX_H
#define MATRIX_H

template<typename T>
class Matrix {
public:
    Matrix(int row, int column);
    ~Matrix();
    void rotateRight();
    void rotateLeft();
    T* operator[](int index);
    void setValue(int row, int column, const T& value);
    T getValue(int row, int column) const;
    T** matrix;
    int rowSize;
    int columnSize;
};

#endif // MATRIX_H
